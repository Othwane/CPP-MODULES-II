#pragma once

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
	std::string target;
public:
	PresidentialPardonForm(/* args */);
	PresidentialPardonForm(std::string const & _target);
	PresidentialPardonForm(PresidentialPardonForm const & presidentForm);
	PresidentialPardonForm& operator=(PresidentialPardonForm const & presidentForm);
	~PresidentialPardonForm();

	void	execute(Bureaucrat const & executor) const;
};
