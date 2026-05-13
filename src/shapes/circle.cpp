#include "point.hpp"
#include "shapes/circle.hpp"
#include <cmath>
#include "draw.hpp"
#include <vector>
#include <numbers>
#include <iostream>


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
@ La methode Circle.draw
@(void: pas de return), dessine le cercle en utilisant draw::draw_picture
*/
void Circle::draw(){
	vector<Point> points = {};
	for(int i=0; i<360; i++){
		points.push_back(Point(center.x+radius*cos(i*numbers::pi/180), center.y+radius*sin(i*numbers::pi/180)));
	}
	draw_picture(points);
}

/*
@La methode Circle.translate
@param Point T, un point
@(void: pas de return), modifie le centre de Cirlce vers T en gardant le même rayon, translation O->T avec O le centre avant modification
*/
void Circle::translate(Point T){
	center.x = T.x;
	center.y = T.y;
}


/*
@La methode Circle.resize
@param ratio de type double, un réel (Positif)
@(void: pas de return), modifie le rayon du cercle en le multipliant par le ratio (ratio > 1: angrandit le cercle/ ratio < 0: cercle plus petit)  
*/
void Circle::resize(double ratio){
	if(ratio<=0){
		cout << "Operation impossible: Veillez donner une valeur > 0" << endl;
	}else{
		radius = radius * ratio;
	}
}

/*
@La methode Circle.equals
@param circle de type Circle
@return un booléen, vérifie si circle est égale au cercle(instance courante) ou non, compare les centres ET les rayons à 10^(-4) près
*/
bool Circle::equals(Circle circle){
	return (abs(radius-circle.radius)<0.0001 && abs(center.x - circle.center.x) <0.0001 && abs(center.y - circle.center.y)<0.0001);
	
}
