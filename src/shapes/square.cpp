#include "point.hpp"
#include "shapes/square.hpp"
#include "draw.hpp" // pour draw_picture
#include <cmath> //  pour std::sqrt, std::cos, std::sin
#include <vector> // pour les listes de points

Square::Square(Point P, Point R) : A(P), C(R) {};

// Calcule la longueur d'un côté.
//Par Pythagore, Diagonale = Côté * racine(2).
//Côté = Diagonale / racine(2).
double Square::side() {
    double diagonale = A.distance(C);
    return diagonale / std::sqrt(2.0);
}
