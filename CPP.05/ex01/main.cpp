#include "Bureaucrat.hpp"

int main(){
	std::cout << "------------------FIRST TEST--------------------" << std::endl;
	try
	{
		Bureaucrat x("XCRAT", 1);
		Form xf("XFORM", 15, 150);
		xf.beSigned(x);
		x.signForm(xf);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "------------------ANOTHER TEST------------------" << std::endl;

	try
	{
		Bureaucrat	y("YCRAT", 5);
		Form	yf("YFORM", 4, 150);
		yf.beSigned(y);
		y.signForm(yf);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "------------------------------------------------" << std::endl;

	return EXIT_SUCCESS;
}
