#pragma once

#include <iostream>
#include <fstream>
#include "Bureaucrat.hpp"

#define HG 1
#define LG 150

class Bureaucrat;

class AForm
{
private:
    std::string const name;
    std::string const target;
    bool is_signed;
    int const gr_sign;
    int const gr_exec;
public:
    AForm(/* args */);
    AForm(std::string const &_name, int const _gr_sign, int const _gr_exec);
    AForm(AForm const & form);
    AForm& operator=(AForm const & form);
    ~AForm();

    std::string const & getName() const ;
    std::string const & getTarget() const;
    bool g_isigned() const;
    int get_gr_sign() const;
    int get_gr_exec() const;

    class GradeTooHighException : public std::exception {
        public:
            const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
        public:
            const char* what() const throw();
    };

    class NotSignedException : public std::exception {
        public:
            const char* what() const throw();
    };

    void    beSigned(Bureaucrat const & crat);
    virtual void    execute(Bureaucrat const & executor) const = 0;
};

