#pragma once

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
public:
	Intern(/* args */);
	Intern(Intern const & intern);
	Intern& operator=(Intern const & intern);
	~Intern();

	AForm* makeForm(std::string const & fname, std::string const & target) const;
	static AForm* makeShrubbery(std::string const & target);
	static AForm* makeRobotomy(std::string const & target);
	static AForm* makePresidential(std::string const & target);
};
