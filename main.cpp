#include "draw.hpp"
#include "point.hpp"
#include "shapes.hpp"
#include <vector>
#include <iostream>

int main() {
	
	// Define points in a vector
	std::vector<Point> points = {
		Point(0, 0),
		Point(100, 0),
		Point(100, 100),
		Point(0, 100),
		Point(0, 0)
		
	};
	
	// Draw the picture by connecting the points
	draw_picture(points);
	Circle C(5, Point(0,0));
	Circle E(5, Point(1,0));
	if(not C.equals(E)){
		std::cout<< "not OK";
	}
	return 0;

}
