//g++ -w -Wall -std=c++0x ./lib_files/Graph.cpp ./lib_files/Window.cpp ./lib_files/GUI.cpp ./lib_files/Simple_window.cpp example.cpp `fltk-config --ldflags --use-images` -o a.out

#include "./lib_files/Simple_window.h"
#include "./lib_files/Graph.h"

int main() 
try{

	using namespace Graph_lib;

	Point t1(200, 50);
	Simple_window win(t1, 1200, 800, "labor 4");

	Smiley s1(Point(600,400), 150);
	s1.set_fill_color(Color::yellow);
	win.attach(s1);
	win.wait_for_button();


}
catch (exception& e) 
{
	cerr << "exception: " <<e.what() << endl;
	keep_window_open();
} 
catch (...) 
{
	cerr << "exception\n";
	keep_window_open();
}