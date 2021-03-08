//g++ GUI/Graph.cpp GUI/Window.cpp GUI/GUI.cpp GUI/Simple_window.cpp ex01.cpp `fltk-config --ldflags --use-images` -o a.out

#include "./GUI/Simple_window.h"
#include "./GUI/Graph.h"

#include <string>
#include <iostream>
#include <vector>

using namespace Graph_lib;

int main()
try {
	Point t1 (100,100);
	Simple_window win (t1,600,400, "Ch12 labor");
	win.wait_for_button();
	
	//01
	Rectangle r{Point{50,50},50,25};
	r.set_color(Color::blue);
	win.attach(r);
	
	Polygon rect;
	rect.add(Point{125, 50});
	rect.add(Point{175, 50});
	rect.add(Point{175, 75});
	rect.add(Point{125, 75});
	rect.set_color(Color::red);
	win.attach(rect);


	win.set_label("Ch 12 1.feladat");
	win.wait_for_button();
	
	//02
	Rectangle rt{Point{200, 50}, 100, 30};
	win.attach(rt);
	
	Text t {Point{205, 75}, "Textbox"};
	t.set_font(Font::helvetica_bold);
	t.set_font_size(20);
	win.attach(t);
	
	win.set_label("2. feladat");
	win.wait_for_button();
	
	//03
	Text t3 {Point{50, 350}, "T"};
	t3.set_font(Font::courier);
	t3.set_font_size(150);
	
	Text t2 {Point{150, 350}, "A"};
	t2.set_font(Font::courier);
	t2.set_font_size(150);
	
	t3.set_color(Color::green);
	t2.set_color(Color::yellow);
	win.attach(t3);
	win.attach(t2);
	
	win.set_label("3. feladat");
	win.wait_for_button();
	
	//04
	Vector_ref<Rectangle> vr;
	int w = 50;
	for(int row = 0; row < 3; ++row) {
		for(int col = 0; col < 3; ++col) {
		vr.push_back(new Rectangle{Point{350+ w*col, 200+w*row}, w, w});
		
		int i = vr.size()-1;
		i % 2 == 0 ? vr[i].set_fill_color(Color::red) : vr[i].set_fill_color(Color::white);
		
		win.attach(vr[i]);
		}
	}
	
	win.set_label("4. feladat");
	win.wait_for_button();
	
	//05
	Rectangle huge {Point{150, 150}, x_max() * 2 / 3, y_max() * 3 / 4};
	huge.set_style(Line_style(Line_style::solid, 8));
	huge.set_color(Color::red);
	
	win.attach(huge);
	win.set_label("5. feladat");
	win.wait_for_button();
	
}
catch(exception& e) {
	cerr << "exception" << e.what() << '\n';
	return 1;
}
catch(...) {
	cerr << "error\n";
	return 2;
}
