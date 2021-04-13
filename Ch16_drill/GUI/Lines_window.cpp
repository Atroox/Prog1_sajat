#include "Lines_window.h"

Lines_window::Lines_window(Point xy, int w, int h, const string& title)
: Window{xy, w, h, title},
next_button{Point{x_max()-150, 0}, 80, 20, "Next point", cb_next},
quit_button{Point{x_max()-70, 0}, 70, 20, "Quit", cb_quit},
next_x{Point{x_max()-310, 0}, 50, 20, "next x:"},
next_y{Point{x_max()-210, 0}, 50, 20, "next y:"},
xy_out{Point{100,0}, 100, 20, "current (x,y):"},
color_menu{Point{x_max()-70, 40}, 70, 20, Menu::vertical, "color"},
menu_button{Point{x_max()-80, 30}, 80, 20, "color menu", cb_menu},
line_style_menu{Point{x_max()-70, 100}, 70, 20, Menu::vertical, "line style"},
line_style_menu_button{Point{x_max()-80, 100}, 80, 20, "style menu", cb_line_style_menu}

{
	attach(next_button);
	attach(quit_button);
	attach(next_x);
	attach(next_y);
	attach(xy_out);
	xy_out.put("no point");
	lines.set_color(Color::black);
	color_menu.attach(new Button{Point{0,0},0,0,"red",cb_red});
	color_menu.attach(new Button{Point{0,0},0,0,"blue",cb_blue});
	color_menu.attach(new Button{Point{0,0},0,0,"black",cb_black});
	line_style_menu.attach(new Button(Point(0, 0), 0, 0, "solid", cb_solid));
	line_style_menu.attach(new Button(Point(0, 0), 0, 0, "dashed", cb_dash));
	line_style_menu.attach(new Button(Point(0, 0), 0, 0, "dotted", cb_dot));


	attach(color_menu);
	color_menu.hide();
	attach(menu_button);
	attach(line_style_menu);
	line_style_menu.hide();
	attach(line_style_menu_button);
	attach(lines);
}

void Lines_window::quit()
{
	hide();
}

void Lines_window::next()
{
	int x = next_x.get_int();
	int y = next_y.get_int();

	lines.add(Point{x,y});

	ostringstream ss;
	ss << '(' << x << ',' << y << ')';

	xy_out.put(ss.str());

	redraw();
}

void Lines_window::cb_red(Address, Address pw)
{
	reference_to<Lines_window>(pw).red_pressed();
}

void Lines_window::cb_blue(Address, Address pw)
{
	reference_to<Lines_window>(pw).blue_pressed();
}

void Lines_window::cb_black(Address, Address pw)
{
	reference_to<Lines_window>(pw).black_pressed();
}

void Lines_window::cb_menu(Address, Address pw)
{
	reference_to<Lines_window>(pw).menu_pressed();
}

void Lines_window::cb_solid(Address, Address pw)
{
	reference_to<Lines_window>(pw).solid_pressed();
}

void Lines_window::cb_dash(Address, Address pw)
{
	reference_to<Lines_window>(pw).dashed_pressed();
}

void Lines_window::cb_dot(Address, Address pw)
{
	reference_to<Lines_window>(pw).dotted_pressed();
}

void Lines_window::cb_line_style_menu(Address, Address pw)
{
	reference_to<Lines_window>(pw).line_style_menu_pressed();
}

void Lines_window::cb_next(Address, Address pw)
{
	reference_to<Lines_window>(pw).next();
}

void Lines_window::cb_quit(Address, Address pw)
{
	reference_to<Lines_window>(pw).quit();
}
