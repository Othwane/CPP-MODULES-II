#pragma once

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
private:
	std::string target;
public:
	ShrubberyCreationForm(/* args */);
	ShrubberyCreationForm(std::string const & _target);
	ShrubberyCreationForm(ShrubberyCreationForm const & shrrform);
	ShrubberyCreationForm & operator=(ShrubberyCreationForm const & shrrform);
	~ShrubberyCreationForm();

	void	execute(Bureaucrat const & executor) const;
};

