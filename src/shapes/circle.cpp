#include "point.hpp"
#include "shapes/circle.hpp"
#include <cmath>
#include "draw.hpp"
#include <vector>
#include <numbers>


using namespace std;

Circle::Circle(double r, Point c) : radius(r), center(c) {};


double Circle::circumference() {  //calculer la circonférence du cercle 
	return 2*numbers::pi*radius;
	
}

double Circle::area() {       //Calcul de surface de cercle
	
	return numbers::pi*radius*radius;

}

void Circle::resize(double ratio){
	radius = radius * ratio;

}

bool Circle::equals(Circle circle){
	return (radius==circle.radius && center.x == circle.center.x && center.y == circle.center.y);
	
}