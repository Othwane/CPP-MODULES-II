#include "Form.hpp"

Form::Form(): name("DEFORM"), is_signed(0), gr_sign(150), gr_exec(150){
}

Form::Form(std::string const &_name, int const _gr_sign, int const _gr_exec):
            name(_name),
            is_signed(0),
            gr_sign(_gr_sign),
            gr_exec(_gr_exec){
                if (gr_sign < HG || gr_exec < HG)
                    throw GradeTooHighException();
                else if (gr_sign > LG || gr_exec > LG)
                    throw GradeTooLowException();
                return;
            }

Form::Form(Form const & form):
            name(form.name),
            is_signed(form.is_signed),
            gr_sign(form.gr_sign),
            gr_exec(form.gr_exec){
                return;
            }


Form& Form::operator=(Form const & form){
    if (this != &form){
        const_cast<std::string&>(name) = form.name;
        is_signed = form.is_signed;
        const_cast<int&>(gr_sign) = form.gr_sign;
        const_cast<int&>(gr_exec) = form.gr_exec;
    }
    return *this;
}

Form::~Form(){}

std::string const & Form::getName() const {
    return this->name;
}

bool Form::g_isigned() const {
    return this->is_signed;
}

int Form::get_gr_sign() const {
    return this->gr_sign;
}

int Form::get_gr_exec() const {
    return this->gr_exec;
}

const char* Form::GradeTooHighException::what() const throw() {
    return "GRADE TOO HIGH";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "GRADE TOO LOW";
}

void    Form::beSigned(Bureaucrat const & crat){
    if (crat.getGrade() <= this->gr_sign)
        this->is_signed = true;
    else
        throw GradeTooLowException();
}

