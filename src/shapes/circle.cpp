#include "point.hpp"
#include "shapes/circle.hpp"

Circle::Circle(double r, Point c) : radius(r), center(c) {};


double Circle::area() {       # Calcul de surface de cercle
	
	return M_PI*radius*radius;

}
