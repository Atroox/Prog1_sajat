#include <iostream>
#include <functional>

int sum(int x, int y)
{
	return x + y;
}

class Add {
public:
	int operator() (int x, int y) const {
		return x+y;

	}
};

struct add_x{
	add_x(int val) : x(val) {}
	int operator() (int y) const {return x + y;}

private:
	int x;
};

int main()
{
	add_x add42(42);
	int i = add42(8);
	int j = add42(12);

	std::cout << i << std::endl;
	std::cout << j << std::endl;

	std::function<int(int, int)> func;

	func = sum;

	std::cout << func(5, 7) << std::endl;


	std::function<int(int, int)> func2;

	Add sum2;

	func2 = sum2;

	std::cout << func2(5, 7) << std::endl;
	std::cout << sum2(5, 7) << std::endl;

	std::function<double(double, double)> sum3 = [](double A, double B) {return A + B;};

	std::cout << sum3(4.6, 5.9) << std::endl;

	return 0;
}