#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(){

	try
	{
		Bureaucrat x("BCRAT", 1);
		ShrubberyCreationForm y("SHRUFORM");
		y.beSigned(x);
		x.executeForm(y);

		RobotomyRequestForm n("ROV");
		n.beSigned(x);
		x.executeForm(n);

		PresidentialPardonForm i("Siii");
		i.beSigned(x);
		x.executeForm(i);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}
