#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(/* args */):
		AForm("PresidentialPardonForm", 25, 5),
		target("DefaulTarget"){
			return ;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const & _target):
		AForm("PresidentialPardonForm", 25, 5),
		target(_target){
			return ;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & presidentForm):
		AForm(presidentForm),
		target(presidentForm.target){
			return ;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm const & presidentForm){
	if (this != &presidentForm)
		this->target = presidentForm.getTarget();
	return *this;
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	if (!this->g_isigned())
		throw NotSignedException();
	else if (this->get_gr_exec() < executor.getGrade())
		throw GradeTooLowException();
	std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(){

}
