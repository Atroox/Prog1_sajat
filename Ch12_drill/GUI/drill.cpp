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

	Function sinus {sin,0,150,Point{10,100},1000,50,50};
	sinus.set_color(Color::yellow);
	win.attach(sinus);
	win.set_label("My window 4");
	win.wait_for_button();

	Polygon poly;
	poly.add(Point{250,200});
	poly.add(Point{300,100});
	poly.add(Point{350,200});

	poly.set_color(Color::magenta);
	poly.set_style(Line_style::dashdot);
	win.attach(poly);
	win.set_label("My window 5");
	win.wait_for_button();

	Rectangle r{Point{25,255}, 150, 75};
	win.attach(r);
	win.set_label("My window 6");
	win.wait_for_button();

	Closed_polyline poly_rect;
	poly_rect.add(Point{100, 100});
	poly_rect.add(Point{200, 100});
	poly_rect.add(Point{200, 150});
	poly_rect.add(Point{100, 150});
	poly_rect.add(Point{75, 125});
	win.attach(poly_rect);
	win.set_label("My window 7");
	win.wait_for_button();

	r.set_fill_color(Color::dark_cyan);
	poly.set_style(Line_style(Line_style::dash,4));
	poly_rect.set_style(Line_style(Line_style::solid,3));
	poly_rect.set_fill_color(Color::white);
	win.set_label("My Window 8");
	win.wait_for_button();

	Text t {Point{75,200}, "Hello, graphical world!"};
	win.attach(t);
	win.set_label("My window 9");
	win.wait_for_button();

	t.set_font(Font::zapf_dingbats);
	t.set_font_size(30);
	win.set_label("My window 10");
	win.wait_for_button();

	Image ii {Point{200,188},"image.jpg"};
	win.attach(ii);
	win.set_label("My window 11");
	win.wait_for_button();

	ii.move(150,50);
	win.set_label("My window 12");
	win.wait_for_button();

	Circle c {Point{100,225},75};
	Ellipse e {Point{100,225}, 100,50};
	e.set_color(Color::dark_red);
	Mark m {Point{100,225},'*'};

	ostringstream oss;
	oss << "screen size: " << x_max() << "*" << y_max()
		<< "; window size: " << win.x_max() << "*" << win.y_max();
	Text sizes {Point{100,20},oss.str()};
	
	Image cal {Point{225,225},"snow_cpp.gif"};
	cal.set_mask(Point{40,40},200,150);

	win.attach(c);
	win.attach(m);
	win.attach(e);
	win.attach(sizes);
	win.attach(cal);
	win.set_label("My window 13");
	win.wait_for_button();
}