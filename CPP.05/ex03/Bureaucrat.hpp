#ifndef BUREAUCRAT__HPP
#define BUREAUCRAT__HPP

#include <iostream>
#include <exception>
#include "AForm.hpp"

#define HG 1
#define LG 150

class AForm;

class Bureaucrat
{
private:
	std::string const name;
	int grade;
public:
	Bureaucrat();
	Bureaucrat(std::string const &_name, int grade);
	Bureaucrat(Bureaucrat const & crat);
	Bureaucrat& operator=(Bureaucrat const & crat);
	~Bureaucrat();

	std::string getName() const ;
	int getGrade() const ;

	class GradeTooHighException : public std::exception {
		public:
			const char * what() const throw();
	};

	class GradeTooLowException : public std::exception {
		public:
			const char * what() const throw();
	};

	void	Increment();
	void	Decrement();

	void	signForm(AForm const & form);
	void	executeForm(AForm const & form);
};

std::ostream& operator<<(std::ostream& x, Bureaucrat const & crat);

#endif
