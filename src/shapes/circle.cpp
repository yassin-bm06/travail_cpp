#include "point.hpp"
#include "shapes/circle.hpp"
#include <cmath>
Circle::Circle(double r, Point c) : radius(r), center(c) {};


double Circle:circumference() {  #calculer la circonférence du cercle 
	return 2*M_PI*radius;
	
}

double Circle::area() {       # Calcul de surface de cercle
	
	return M_PI*radius*radius;

}
