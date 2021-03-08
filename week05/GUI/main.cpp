/*
    g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`
*/
#include "Simple_window.h"
#include "Graph.h"

double one(double) { return 1; }

double square(double x) { return x*x; }

double slope(double x) { return x/2; }

double sloping_cos (double x) { return cos(x)+slope(x); }

int main()
{
    using namespace Graph_lib;

    int xmax = 600;
    int ymax = 400;

    int x_orig = xmax/2;
    int y_orig = ymax/2;

    int rmin = -11;
    int rmax = 11;
    
    int n_points = 400;

    Simple_window win {Point{100,100}, xmax, ymax, "Canvas"};

	Point origo {x_orig, y_orig};

	int xlength = xmax - 40;
	int ylength = ymax - 40;

	int xscale = 30, yscale = 30;

	Function s(one, rmin, rmax, origo, n_points, xscale, yscale);

	Function sl(slope, rmin, rmax, origo, n_points, xscale, yscale);

	Function sq(square, rmin, rmax, origo, n_points, xscale, yscale);

	Function sl_cos(sloping_cos, rmin, rmax, origo, n_points, xscale, yscale);


	win.attach(s);
	win.attach(sl);
	win.attach(sq);
	win.attach(sl_cos);

    win.wait_for_button();

}
