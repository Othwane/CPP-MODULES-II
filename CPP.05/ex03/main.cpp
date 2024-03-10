#include "Intern.hpp"

int main(){

	try
	{
		Bureaucrat x("BCRAT", 1);
		Intern internform;
		AForm* f;

		f = internform.makeForm("shrubbery creation", "Goku");
		f->beSigned(x);
		x.executeForm(*f);

		f = internform.makeForm("robotomy request", "Cooper");
		f->beSigned(x);
		x.executeForm(*f);

		f = internform.makeForm("presidential pardon", "Iori");
		f->beSigned(x);
		x.executeForm(*f);

		f = internform.makeForm("NONVALID", "NON");
		f->beSigned(x);
		x.executeForm(*f);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}
