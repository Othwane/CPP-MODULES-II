#pragma once

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
private:
	std::string target;
public:
	RobotomyRequestForm(/* args */);
	RobotomyRequestForm(std::string const & _target);
	RobotomyRequestForm(RobotomyRequestForm const & robotform);
	RobotomyRequestForm& operator=(RobotomyRequestForm const & robotform);
	~RobotomyRequestForm();

	void	execute(Bureaucrat const & executor) const;
};
