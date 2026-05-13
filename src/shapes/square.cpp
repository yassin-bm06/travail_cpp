#include "point.hpp"
#include "shapes/square.hpp"
#include <cmath> //  pour std::sqrt, std::cos, std::sin
#include "draw.hpp" // Nécessaire pour la fonction draw_picture
#include <vector>   // Nécessaire pour les listes de points

Square::Square(Point P, Point R) : A(P), C(R) {};


/*calcule d'une longeur d'un coté a l'aide du théoreme de pythagore 
Côté = Diagonale /sqrt(2)*/
double Square::side() {
    double diagonale = A.distance(C);
    return diagonale / std::sqrt(2.0);
}
// Périmètre : 4 * côté
double Square::perimeter() {
    return 4.0 * side();
}
// Aire : côté * côté
double Square::area() {
    double s = side();
    return s * s;
}
// Le centre du carré est le milieu du segment [AC]
Point Square::center() {
    return Point((A.x + C.x) / 2.0, (A.y + C.y) / 2.0);
}
// Dessin : On calcule les deux autres coins B et D à partir de la diagonale
void Square::draw() {
    std::vector<Point> points_du_carre;
    Point M = center(); // Le centre

    // On calcule le vecteur qui va du centre (M) vers A
    double vx = A.x - M.x;
    double vy = A.y - M.y;

    // Pour trouver le coin B, on tourne ce vecteur de 90 degrés (-vy, vx)
    Point B(M.x - vy, M.y + vx);
    
    // Pour trouver le coin D, on tourne le vecteur de -90 degrés (vy, -vx)
    Point D(M.x + vy, M.y - vx);

    // On ajoute les 4 coins dans le bon ordre, puis on remet le point A à la fin pour fermer le dessin.
    points_du_carre.push_back(A);
    points_du_carre.push_back(B);
    points_du_carre.push_back(C);
    points_du_carre.push_back(D);
    points_du_carre.push_back(A);

    draw_picture(points_du_carre);
}
// Déplace le carré : on décale les points A et C
void Square::translate(Point T) {
    A.x += T.x;
    A.y += T.y;
    C.x += T.x;
    C.y += T.y;
}
