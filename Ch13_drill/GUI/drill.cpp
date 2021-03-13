// g++ drill.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o drill `fltk-config --ldflags --use-images`

#include "Graph.h"
#include "Simple_window.h"

int main() 
{
	Simple_window win(Point{0,0}, 800, 1000, "Drill");
	win.wait_for_button();

	int x_size = 800;
	int y_size = 800;
	int x_grid = 100;
	int y_grid = 100;

	Lines grid;
	for (int x=x_grid; x<x_size; x+=x_grid)
		grid.add(Point{x,0},Point{x,y_size});

	for (int y = y_grid; y<y_size; y+=y_grid)
		grid.add(Point{0,y},Point{x_size,y});

	grid.set_style(Line_style::dot);

	win.attach(grid);
	win.wait_for_button();

	Vector_ref<Rectangle> rects;
	for (int i = 0; i < x_size; i += x_grid) {
		rects.push_back(new Rectangle{Point{i,i}, Point{i+x_grid,i+y_grid}});
		rects[rects.size() - 1].set_color(Color::red);
		rects[rects.size() - 1].set_fill_color(Color::red);
		win.attach(rects[rects.size() - 1]);
	}

	win.wait_for_button();

    // 4. Add 3 copies of a 200x200 image
	Image cpp1 {Point{0,300}, "cpp.gif"};
	Image cpp2 {Point{300,600}, "cpp.gif"};
	Image cpp3 {Point{600,100}, "cpp.gif"};

	win.attach(cpp1);
	win.attach(cpp2);
	win.attach(cpp3);
	win.wait_for_button();

	Image ibm {Point{0, 0}, "IBM.jpeg"};
	win.attach(ibm);
	win.wait_for_button();

	for (int i = 0; i < x_size; i+=x_grid) {
        for (int j = 0; j < y_size; j+=y_grid) {
            ibm.move(x_grid, 0);
            win.wait_for_button();
        }
        ibm.move(-x_size, y_grid);          
        win.wait_for_button();
    }
}