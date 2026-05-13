#include "point.hpp"
#include "shapes/circle.hpp"
#include <cmath>
#include "draw.hpp"
#include <vector>
#include <numbers>


using namespace std;

Circle::Circle(double r, Point c) : radius(r), center(c) {};



/*
@La methode Circle.circumference
@return en type double, la circomference du cercle en fonction de son rayon
*/

double Circle::circumference() { 
	return 2*numbers::pi*radius;
	
}

/*
@La methode Circle.area
@return en type double, l'aire du cercle calculé en fonction du rayon déjà donné
*/

double Circle::area() {       //Calcul de surface de cercle
	
	return numbers::pi*radius*radius;

}


/*
@La methode Circle.resize
@param ratio de type double, un réel (Positif)
@(void: pas de return), modifie le rayon du cercle en le multipliant par le ratio (ratio > 1: angrandit le cercle/ ratio < 0: cercle plus petit)  
*/
void Circle::resize(double ratio){
	radius = radius * ratio;

}

/*
@La methode Circle.equals
@param circle de type Circle
@return un booléen, vérifie si circle est égale au cercle(instance courante) ou non, compare les centres ET les rayons 
*/
bool Circle::equals(Circle circle){
	return (radius==circle.radius && center.x == circle.center.x && center.y == circle.center.y);
	
}
