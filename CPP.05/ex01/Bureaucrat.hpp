#ifndef BUREAUCRAT__HPP
#define BUREAUCRAT__HPP

#include <iostream>
#include "Form.hpp"
#include <exception>

#define HG 1
#define LG 150

class Form;

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

	void	signForm(Form const & form);

};

std::ostream& operator<<(std::ostream& x, Bureaucrat const & crat);

#endif
