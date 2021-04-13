/*
    g++ main.cpp Graph.cpp Window.cpp GUI.cpp Lines_window.cpp -o main `fltk-config --ldflags --use-images`
*/
#include "Lines_window.h"
#include "Graph.h"

int main()
try {
	using namespace Graph_lib;

	Lines_window win{Point{100, 100}, 600, 400, "lines"};

	return gui_main();
}
catch(exception& e) {
	cerr << "exception: " <<e.what() << endl;
	return 1;
}
catch (...) {
	cerr << "Some exception" << endl;
	return 2;
}