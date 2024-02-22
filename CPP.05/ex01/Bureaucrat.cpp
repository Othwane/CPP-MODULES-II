#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): name("DEFAUCRAT"), grade(-1) {}

Bureaucrat::Bureaucrat(std::string const &_name, int _grade): 
			name(_name),
			grade(_grade){
				if (this->grade < HG)
					throw GradeTooHighException();
				else if (this->grade > LG)
					throw GradeTooLowException();
				return ;
			}

Bureaucrat::Bureaucrat(Bureaucrat const & crat): name(crat.name), grade(crat.grade){}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const & crat){
	if (this != &crat){
		const_cast <std::string&>(name) = crat.name;
		this->grade = crat.getGrade();
	}
	return *this;
}

Bureaucrat::~Bureaucrat(){}

std::string Bureaucrat::getName() const {
	return this->name;
}

int Bureaucrat::getGrade() const {
	return this->grade;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "GRADE TOO HIGH";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "GRADE TOO LOW";
}

void	Bureaucrat::Increment() {
	if (this->grade - 1 < HG)
		throw GradeTooHighException();
	this->grade--;
}

void	Bureaucrat::Decrement() {
	if (this->getGrade() + 1 > LG)
		throw GradeTooLowException();
	this->grade++;
}

void	Bureaucrat::signForm(Form const & form){
	if (form.g_isigned())
		std::cout << this->name << " signed " << form.getName() << std::endl;
	else
		std::cout << this->name << " couldn't sign " << form.getName() << " because grade too low." << std::endl;
}

std::ostream& operator<<(std::ostream& x, Bureaucrat const & crat){
	x << crat.getName() << ", bureaucrat grade " << crat.getGrade() << std::endl;
	return x;
}
