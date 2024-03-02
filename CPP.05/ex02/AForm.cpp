#include "AForm.hpp"

AForm::AForm(): name("DEFORM"), is_signed(0), gr_sign(150), gr_exec(150){
}

AForm::AForm(std::string const &_name, int const _gr_sign, int const _gr_exec):
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

AForm::AForm(AForm const & form):
            name(form.name),
            is_signed(form.is_signed),
            gr_sign(form.gr_sign),
            gr_exec(form.gr_exec){
                return;
            }


AForm& AForm::operator=(AForm const & form){
    if (this != &form){
        const_cast<std::string&>(name) = form.name;
        is_signed = form.is_signed;
        const_cast<int&>(gr_sign) = form.gr_sign;
        const_cast<int&>(gr_exec) = form.gr_exec;
    }
    return *this;
}

AForm::~AForm(){}

std::string const & AForm::getName() const {
    return this->name;
}

std::string const & AForm::getTarget() const {
    return this->target;
}

bool AForm::g_isigned() const {
    return this->is_signed;
}

int AForm::get_gr_sign() const {
    return this->gr_sign;
}

int AForm::get_gr_exec() const {
    return this->gr_exec;
}

const char* AForm::GradeTooHighException::what() const throw() {
    return "GRADE TOO HIGH";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "GRADE TOO LOW";
}

const char* AForm::NotSignedException::what() const throw() {
    return "FORM NOT SIGNED";
}

void    AForm::beSigned(Bureaucrat const & crat){
    if (crat.getGrade() <= this->gr_sign)
        this->is_signed = true;
    else
        throw GradeTooLowException();
}
