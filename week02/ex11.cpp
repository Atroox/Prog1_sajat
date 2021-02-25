		#include "./GUI/Simple_window.h"
		#include "./GUI/Graph.h"

		#include <string>
		#include <iostream>
		#include <vector>

using namespace Graph_lib;

int main()
try{

	Point t1 {100, 100};
	Simple_window win {t1, 600, 400, "Feladat 1. "};

	constexpr double pi = 3.14159265;
	const int x = win.x_max() / 2-50;
	const int y = win.y_max() / 2-50;

	//Triangle 
	Polygon tri;

	int alt = sin(60*pi/180)*100;
	tri.add(Point{x, y + alt});
	tri.add(Point{x + 50, y});
	tri.add(Point{x + 100, y + alt});
	tri.set_color(Color::red);

	win.attach(tri);
	win.wait_for_button();

	//Square

	Rectangle sqr {Point{x, y},100, 100};
	sqr.set_color(Color::green);
	win.attach(sqr);
	win.wait_for_button();

	//Pentagon

	Polygon pent;
	 int pr = 50 / sin(36*pi/100);
	 int px = 300;
	 int py = 200 - pr;

	 pent.add(Point{px, py});

	 px += sin(54*pi/180)*100;
	 py += cos(54*pi/180)*100;
	 pent.add(Point{px, py});

	 px -= 100;
	 pent.add(Point{px,py});

	 
	 px -= sin(72*pi/180)*100;
	 py -= cos(72*pi/180)*100;
	 pent.add(Point{px, py});


}
catch(exception e){
	cerr << "exception: " <<e.what() << '\n';
	return 1;
}
catch(...) {
	cerr << "error\n";
	return 2;
}
