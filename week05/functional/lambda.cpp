#include <iostream>
/*
[] semmit sem kap el
[&] minden capture referencia szerinte
[=] minden capture érték szerinti
[&A =B] A referencia szerinti, B érték szerinti
[=, &A] A referencia szerinti, minden más pedig érték szerinti 
[*this] this
*/

int main()
{
	[](){
		std::cout << "Hello C++ lambda" << std::endl;
	}
	();

	[](){
		std::cout << "Hello C++ lambda2" << std::endl;
	}
	();

	auto sum = [](double A, double B) 
	{return A + B;};

	auto sum2 = [](double A, double B) -> double 
	{return A +B;};

	std::cout << sum(3.25, 5.65) << std::endl;
	std::cout << sum2(3.25, 5.65) << std::endl;

	double pi = 3.1416;

	auto func = [](double pi){std::cout << "The value of pi is " << pi << std::endl;};
	func(pi);

	auto func2 = [pi](){std::cout << "The value of pi is " << pi << std::endl;};
	func2();

	auto gene_lambda = [](auto arg) 
	{return arg + arg;};

	std::cout << gene_lambda(5) << std::endl;
	std::cout << gene_lambda(3.1416) << std::endl;

	int x = 4;
	auto y = [&r = x, x= x + 1] () -> int 
	{r += 2;return x*x;}
	();

	std::cout << y << std::endl;
	std::cout << x << std::endl;

	

	return 0; 
}