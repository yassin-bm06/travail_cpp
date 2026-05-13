#include "shapes/triangle.hpp"
#include "draw.hpp"

#include <cmath>
#include <vector>

using namespace std;

// Initialise les trois sommets du triangle
Triangle::Triangle(Point P, Point Q, Point R) {
    A = P;
    B = Q;
    C = R;
}

// Retourne la somme des longueurs AB + BC + CA
double Triangle::perimeter() {
    return A.distance(B) + B.distance(C) + C.distance(A);
}

// Calcule l’aire avec la formule du déterminant
double Triangle::area() {
    return abs(
        (A.x * (B.y - C.y) +
         B.x * (C.y - A.y) +
         C.x * (A.y - B.y)) / 2.0
    );
}

// Retourne le centre de gravité (barycentre)
Point Triangle::center() {
    return Point(
        (A.x + B.x + C.x) / 3.0,
        (A.y + B.y + C.y) / 3.0
    );
}

// Dessine le contour en reliant les sommets
// Le dernier A ferme la forme
void Triangle::draw() {
    vector<Point> points = {A, B, C, A};
    draw_picture(points);
}

// Déplace chaque sommet selon le vecteur T
void Triangle::translate(Point T) {
    A.x += T.x;
    A.y += T.y;

    B.x += T.x;
    B.y += T.y;

    C.x += T.x;
    C.y += T.y;
}

// Redimensionne le triangle autour du centre
// ratio > 1 : agrandit
// ratio < 1 : réduit
void Triangle::resize(double ratio) {
    Point G = center();

    A.x = G.x + ratio * (A.x - G.x);
    A.y = G.y + ratio * (A.y - G.y);

    B.x = G.x + ratio * (B.x - G.x);
    B.y = G.y + ratio * (B.y - G.y);

    C.x = G.x + ratio * (C.x - G.x);
    C.y = G.y + ratio * (C.y - G.y);
}

// Rotation autour du centre du triangle
// angle en radians
void Triangle::rotate(double angle) {
    Point G = center();

    // Rotation appliquée à un sommet
    auto rotatePoint = [&](Point& P) {

        // Passage en coordonnées relatives au centre
        double dx = P.x - G.x;
        double dy = P.y - G.y;

        // Rotation 2D standard
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

// Vérifie si les sommets correspondent exactement
bool Triangle::equals(Triangle triangle) {
    return A.x == triangle.A.x && A.y == triangle.A.y &&
           B.x == triangle.B.x && B.y == triangle.B.y &&
           C.x == triangle.C.x && C.y == triangle.C.y;
}

// Vérifie Pythagore sur les 3 combinaisons possibles
// eps compense les erreurs de précision
bool Triangle::isRightAngled() {
    double AB = A.distance(B);
    double BC = B.distance(C);
    double CA = C.distance(A);

    const double eps = 1e-6;

    return abs(AB * AB + BC * BC - CA * CA) < eps ||
           abs(AB * AB + CA * CA - BC * BC) < eps ||
           abs(BC * BC + CA * CA - AB * AB) < eps;
}

// Vérifie si les trois côtés sont égaux
bool Triangle::isEquilateral() {
    double AB = A.distance(B);
    double BC = B.distance(C);
    double CA = C.distance(A);

    const double eps = 1e-6;

    return abs(AB - BC) < eps &&
           abs(BC - CA) < eps;
}

// Vérifie si au moins deux côtés sont égaux
bool Triangle::isIsoceles() {
    double AB = A.distance(B);
    double BC = B.distance(C);
    double CA = C.distance(A);

    const double eps = 1e-6;

    return abs(AB - BC) < eps ||
           abs(BC - CA) < eps ||
           abs(CA - AB) < eps;
}

// Calcule le cercle inscrit
// Centre = intersection des bissectrices
// Rayon = aire / demi-périmètre
Circle Triangle::inscribedCircle() {
    double a = B.distance(C);
    double b = A.distance(C);
    double c = A.distance(B);

    Point I(
        (a * A.x + b * B.x + c * C.x) / (a + b + c),
        (a * A.y + b * B.y + c * C.y) / (a + b + c)
    );

    double r = area() / (perimeter() / 2.0);

    return Circle(I, r);
}

// Calcule le cercle passant par A, B et C
// Centre = intersection des médiatrices
Circle Triangle::circumscribedCircle() {
    double D = 2 * (
        A.x * (B.y - C.y) +
        B.x * (C.y - A.y) +
        C.x * (A.y - B.y)
    );

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
