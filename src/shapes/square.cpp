#include "point.hpp"
#include "shapes/square.hpp"
#include <cmath> //  pour std::sqrt, std::cos, std::sin

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

