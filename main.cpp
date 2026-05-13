#include "draw.hpp"
#include "point.hpp"
#include "shapes.hpp"
#include <vector>
#include <iostream>

int main() {
	
	// Define points in a vector

std::vector<Point> point = {
		Point(0, 0),
		Point(850, 0),
		Point(850, 850),
		Point(0, 850),
		Point(0, 0)
		
	};
std::vector<Point> pointss = {
		Point(0, 0),
		Point(100, 0),
		Point(100, 100),
		Point(0, 100),
		Point(0, 0)
		
	};
	
	// Draw the picture by connecting the points
	draw_picture(point);
	draw_picture(pointss);
	Circle C(5, Point(0,0));
	Circle E(5, Point(1,0));
	Circle H(6,Point(3,0));
	if(not C.equals(E)){
		std::cout<< "not OK";
	}
	C.draw();
	E.draw();
	H.draw();
	Triangle T1(Point(0,0),Point(100,0),Point(50,80));
	Triangle T2(Point(0,0),Point(1000,0),Point(500,800));
	Triangle T3(Point(55,32),Point(10,90),Point(550,80));


T1.draw();
T2.draw();
T3.draw();


	std::cout<<T1.perimeter();

	return 0;

}
