```cpp id="u7n4zk"
#include "shapes/triangle.hpp"
#include "draw.hpp"

#include <cmath>
#include <vector>

using namespace std;

// ==============================
// Constructeur
// Initialise les trois sommets du triangle
// ==============================
Triangle::Triangle(Point P, Point Q, Point R) {
    A = P;
    B = Q;
    C = R;
}

// ==============================
// perimeter()
// Retourne la somme des longueurs
// des trois côtés du triangle
// ==============================
double Triangle::perimeter() {
    return A.distance(B) + B.distance(C) + C.distance(A);
}

// ==============================
// area()
// Calcule l’aire grâce à la formule
// du déterminant (Shoelace formula)
// ==============================
double Triangle::area() {
    return abs(
        (A.x * (B.y - C.y) +
         B.x * (C.y - A.y) +
         C.x * (A.y - B.y)) / 2.0
    );
}

// ==============================
// center()
// Retourne le centre de gravité
// (barycentre) du triangle
// ==============================
Point Triangle::center() {
    return Point(
        (A.x + B.x + C.x) / 3.0,
        (A.y + B.y + C.y) / 3.0
    );
}

// ==============================
// draw()
// Dessine le triangle en reliant
// A -> B -> C -> A
// draw_picture est fourni par draw.cpp
// ==============================
void Triangle::draw() {
    vector<Point> points = {A, B, C, A};

    draw_picture(points);
}

// ==============================
// translate(Point T)
// Déplace entièrement le triangle
// selon le vecteur de translation T
// ==============================
void Triangle::translate(Point T) {
    A.x += T.x;
    A.y += T.y;

    B.x += T.x;
    B.y += T.y;

    C.x += T.x;
    C.y += T.y;
}

// ==============================
// resize(double ratio)
// Agrandit ou réduit le triangle
// autour de son centre de gravité
// ratio > 1  : agrandissement
// ratio < 1  : réduction
// ==============================
void Triangle::resize(double ratio) {
    Point G = center();

    A.x = G.x + ratio * (A.x - G.x);
    A.y = G.y + ratio * (A.y - G.y);

    B.x = G.x + ratio * (B.x - G.x);
    B.y = G.y + ratio * (B.y - G.y);

    C.x = G.x + ratio * (C.x - G.x);
    C.y = G.y + ratio * (C.y - G.y);
}

// ==============================
// rotate(double angle)
// Fait tourner le triangle autour
// de son centre de gravité
// angle en radians
// sens trigonométrique
// ==============================
void Triangle::rotate(double angle) {
    Point G = center();

    // Fonction locale : rotation d’un sommet
    auto rotatePoint = [&](Point& P) {

        // Translation temporaire :
        // on place le centre à l’origine
        double dx = P.x - G.x;
        double dy = P.y - G.y;

        // Formule de rotation 2D
        double newX = dx * cos(angle) - dy * sin(angle);
        double newY = dx * sin(angle) + dy * cos(angle);

        // Retour au repère initial
        P.x = G.x + newX;
        P.y = G.y + newY;
    };

    rotatePoint(A);
    rotatePoint(B);
    rotatePoint(C);
}

// ==============================
// equals(Triangle triangle)
// Vérifie si deux triangles ont
// exactement les mêmes sommets
// ==============================
bool Triangle::equals(Triangle triangle) {
    return A.x == triangle.A.x && A.y == triangle.A.y &&
           B.x == triangle.B.x && B.y == triangle.B.y &&
           C.x == triangle.C.x && C.y == triangle.C.y;
}

// ==============================
// isRightAngled()
// Vérifie si le triangle est rectangle
// via le théorème de Pythagore
// eps évite les erreurs liées
// aux approximations numériques
// ==============================
bool Triangle::isRightAngled() {
    double AB = A.distance(B);
    double BC = B.distance(C);
    double CA = C.distance(A);

    const double eps = 1e-6;

    return abs(AB * AB + BC * BC - CA * CA) < eps ||
           abs(AB * AB + CA * CA - BC * BC) < eps ||
           abs(BC * BC + CA * CA - AB * AB) < eps;
}

// ==============================
// isEquilateral()
// Vérifie si les trois côtés
// ont la même longueur
// ==============================
bool Triangle::isEquilateral() {
    double AB = A.distance(B);
    double BC = B.distance(C);
    double CA = C.distance(A);

    const double eps = 1e-6;

    return abs(AB - BC) < eps &&
           abs(BC - CA) < eps;
}

// ==============================
// isIsoceles()
// Vérifie si au moins deux côtés
// sont de même longueur
// ==============================
bool Triangle::isIsoceles() {
    double AB = A.distance(B);
    double BC = B.distance(C);
    double CA = C.distance(A);

    const double eps = 1e-6;

    return abs(AB - BC) < eps ||
           abs(BC - CA) < eps ||
           abs(CA - AB) < eps;
}

// ==============================
// inscribedCircle()
// Calcule le cercle inscrit
// (tangent aux trois côtés)
// ==============================
Circle Triangle::inscribedCircle() {

    // Longueurs des côtés opposés
    double a = B.distance(C);
    double b = A.distance(C);
    double c = A.distance(B);

    // Centre du cercle inscrit :
    // barycentre pondéré
    Point I(
        (a * A.x + b * B.x + c * C.x) / (a + b + c),
        (a * A.y + b * B.y + c * C.y) / (a + b + c)
    );

    // Rayon :
    // aire / demi-périmètre
    double r = area() / (perimeter() / 2.0);

    return Circle(I, r);
}

// ==============================
// circumscribedCircle()
// Calcule le cercle circonscrit
// passant par A, B et C
// ==============================
Circle Triangle::circumscribedCircle() {

    // Déterminant principal
    double D = 2 * (
        A.x * (B.y - C.y) +
        B.x * (C.y - A.y) +
        C.x * (A.y - B.y)
    );

    // Coordonnées du centre
    Point O(
        (
            (A.x * A.x + A.y * A.y) * (B.y - C.y) +
            (B.x * B.x + B.y * B.y) * (C.y - A.y) +
            (C.x * C.x + C.y * C.y) * (A.y - B.y)
        ) / D,

        (
            (A.x * A.x + A.y * A.y) * (C.x - B.x) +
            (B.x * B.x + B.y * B.y) * (A.x - C.x) +
            (C.x * C.x + C.y * C.y) * (B.x - A.x)
        ) / D
    );

    // Rayon = distance centre -> sommet
    double r = O.distance(A);

    return Circle(O, r);
}
```
