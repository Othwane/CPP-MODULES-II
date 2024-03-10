#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(/* args */):
		AForm("RobotomyRequestForm", 72, 45),
		target("Default target"){
			return ;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const & _target):
		AForm("RobotomyRequestForm", 72, 45),
		target(_target){
			return ;
}


RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & robotform):
		AForm(robotform),
		target(robotform.target){
			return ;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm const & robotform){
	if (this != &robotform)
		this->target = robotform.getTarget();
	return *this;
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	if (!this->g_isigned())
		throw NotSignedException();
	else if (this->get_gr_exec() < executor.getGrade())
		throw GradeTooLowException();
	std::cout << "MAKING SOME NOOOOOOOISE" << std::endl;
	if (std::rand() % 2)
		std::cout << target << " has been robotomized successfully" << std::endl;
	else
		std::cout << "robotomy failed" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(){
}

