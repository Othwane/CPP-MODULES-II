#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"


int main(){

	try
	{
		Bureaucrat x("BCRAT", 198);
		ShrubberyCreationForm y("SHRUFORM");
		y.beSigned(x);
		x.executeForm(y);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}
