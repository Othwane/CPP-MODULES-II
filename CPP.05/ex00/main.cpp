#include "Bureaucrat.hpp"

int main(){
	std::cout << "------------------FIRST TEST--------------------" << std::endl;
	try
	{
		Bureaucrat x("XCRAT", 145);
		while (1){
			std::cout << x;
			x.Decrement();
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "------------------ANOTHER TEST------------------" << std::endl;

	try
	{
		Bureaucrat y("YCRAT", 5);
		while (1){
			std::cout << y;
			y.Increment();
		}

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "------------------ANOTHER TEST------------------" << std::endl;

	try
	{
		Bureaucrat z("ZCRAT", 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "------------------ANOTHER TEST------------------" << std::endl;

	try
	{
		Bureaucrat a("", 151);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "------------------------------------------------" << std::endl;

	return EXIT_SUCCESS;
}
