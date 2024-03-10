#include "Intern.hpp"

Intern::Intern(/* args */){}

Intern::Intern(Intern const & intern){
	(void)intern;
	return;
}

Intern& Intern::operator=(Intern const & intern) {
	(void)intern;
	return *this;
}

Intern::~Intern(){}

AForm* Intern::makeShrubbery(std::string const & target){
	return new ShrubberyCreationForm(target);
}

AForm* Intern::makeRobotomy(std::string const & target){
	return new RobotomyRequestForm(target);
}

AForm* Intern::makePresidential(std::string const & target){
	return new PresidentialPardonForm(target);
}

AForm*	Intern::makeForm(std::string const & fname, std::string const & target) const{
	int i;
	std::string forms[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm* (*fforms[3])(std::string const & target) = {&Intern::makeShrubbery, &Intern::makeRobotomy, &Intern::makePresidential};
	for (i = 0; i < 3 && fname != forms[i]; i++);
	if (i > 2)
		throw std::runtime_error("Invalid Form");
	else
		return fforms[i](target);
}
