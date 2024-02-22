#pragma once

#include <iostream>
#include "Bureaucrat.hpp"

#define HG 1
#define LG 150

class Bureaucrat;

class Form
{
private:
    std::string const name;
    bool is_signed;
    int const gr_sign;
    int const gr_exec;
public:
    Form(/* args */);
    Form(std::string const &_name, int const _gr_sign, int const _gr_exec);
    Form(Form const & form);
    Form& operator=(Form const & form);
    ~Form();

    std::string const & getName() const ;
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

    void    beSigned(Bureaucrat const & crat);
};

