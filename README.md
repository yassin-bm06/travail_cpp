# travail_cpp
projet imformatique 1ere année 
groupe 2A peip1
Membre : -Khaled louati (chef)
         -Youssef ghalleb (collaborateur) 
         -Yassin ben Mansour  (collaborateur)
         -Jad Abi Kaedbey (collaborateur)
         
pour utiliser notre programme il faut:
-lancer un terminal git sur ca machine (chercher dans votre barre de recherche "git CMD))
-cloner le projet avec la commande "git clone 

!! 
#include <cassert>
#include <numbers>

using namespace std;
"
         Circle c1(15.7, Point(1,1));
	Circle c2(4, Point(1,1));
	Circle c3(4, Point(0,0));
	assert(abs(c1.area() - 774.3711) <= 0.0001);
	assert(abs(c2.area() - 4*4*numbers::pi) <= 0.0001);
	assert(abs(c3.area() - 50.2654) <= 0.0001);
	assert(abs(c1.circumference() - 2*15.7*numbers::pi) <= 0.0001);
	assert(abs(c2.circumference() - 2*4*numbers::pi) <= 0.0001);
	assert(abs(c3.circumference() - 2*4*numbers::pi) <= 0.0001);
	c1.translate(Point(0,0));
	c2.translate(Point(5,5));
	assert(c1.center.x == Point(0,0).x && c1.center.y == Point(0,0).y);
	assert(c1.center.x == Point(5,5).x && c1.center.y == Point(5,5).y);
	c2.translate(Point(0,0));
	assert(c2.equals(c3));
	assert(c1.equals(c2) == false);
	assert(c3.equals(Circle(4, Point(5,5)))== false);
	c1.resize(2);
	c3.resize(0);
	c2.resize(-5);
	assert(abs(c1.radius - 2*15.7) <=0.0001);
	assert(abs(c2.radius - 4) <= 0.0001);
	assert(abs(c3.radius - 4) <= 0.0001);
"
