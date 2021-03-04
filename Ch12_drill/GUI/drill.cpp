// g++ drill.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o drill `fltk-config --ldflags --use-images`

#include "Graph.h"
#include "Simple_window.h"

int main() 
{
	Point tl {100, 100};

	Simple_window win(tl, 600, 400, "My window");
	win.wait_for_button();

	Axis xa {Axis::x, Point{10, 350}, 300, 12, "x tengely"};

	win.attach(xa);
	win.set_label("My window 2");
	win.wait_for_button();

	Axis ya {Axis::y, Point{10, 350}, 300, 12, "y tengely"};
	ya.set_color(Color::red);
	ya.label.set_color(Color::dark_green);
	win.attach(ya);
	win.set_label("My window 3");
	win.wait_for_button();

	Function sinus {sin,0,150,Point{10,300},1000,50,50};
	win.attach(sinus);
	win.set_label("My window 4");
	win.wait_for_button();
}