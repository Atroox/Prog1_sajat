// g++ drill.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o drill `fltk-config --ldflags --use-images`

#include "Graph.h"
#include "Simple_window.h"

double one(double) { return 1; }
double slope(double x) { return x/2; }
double square(double x) { return x*x; }
double sloping_cos(double x) { return cos(x) + slope(x); }

int main()
{
	Simple_window win(Point{100,100}, 600, 600, "Function graphs");

	Axis x {Axis::x, Point{100,300}, 400, 20, "1==20 pixels"};
	Axis y {Axis::y, Point{300,500}, 400, 20, "1==20 pixels"};

	x.set_color(Color::red);
	y.set_color(Color::red);

	win.attach(x);
	win.attach(y);

	constexpr int r_min = -10;
	constexpr int r_max = 11;

	constexpr int n_points = 400;

	constexpr int x_scale = 20;
	constexpr int y_scale = 20;

	const Point orig {300,300};

	Function s {one,r_min,r_max,orig,n_points,x_scale,y_scale};
	Function s2 {slope,r_min,r_max,orig,n_points,x_scale,y_scale};
	Function s3 {[](double x) { return x * x; }, r_min, r_max, orig, n_points, x_scale, y_scale};
	Function s4 {cos, r_min, r_max, orig, n_points, x_scale, y_scale};

	s4.set_color(Color::blue);

	Function s5 {[](double x) { return cos(x) + slope(x); }, r_min, r_max, orig, n_points, x_scale, y_scale};

	Text t {Point{100,410}, "x/2"};

	win.attach(s);
	win.attach(s2);
	win.attach(s3);
	win.attach(s4);
	win.attach(s5);

	win.attach(t);

	win.wait_for_button();
}