#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(/* args */):
		AForm("ShrrubberyCreationForm", 145, 137),
		target("DefaulTarget"){
			return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const & _target):
		AForm("ShrrubberyCreationForm", 145, 137),
		target(_target){
			return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & shrrform):
		AForm(shrrform),
		target(shrrform.target){
			return ;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm const & shrrform){
	if (this != &shrrform)
        this->target = shrrform.target;
    return (*this);
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	if (!this->g_isigned())
		throw NotSignedException();
	else if (this->get_gr_exec() < executor.getGrade())
		throw GradeTooLowException();
	std::ofstream filename;
	filename.open(this->target+ "_shrubbery");
	if (!filename.is_open()){
		std::cerr << "error: can't open "<< target + "_shrubbery" << " file" << std::endl;
		return;
	}
	filename << "                                                         ." << std::endl;
	filename << "                                              .         ;" << std::endl;
	filename << "                 .              .              ;%     ;;" << std::endl;
	filename << "                   ,           ,                :;%  %;" << std::endl;
	filename << "                    :         ;                   :;%;'     .," << std::endl;
	filename << "           ,.        %;     %;            ;        %;'    ,;" << std::endl;
	filename << "             ;       ;%;  %%;        ,     %;    ;%;    ,%'" << std::endl;
	filename << "              %;       %;%;      ,  ;       %;  ;%;   ,%;'" << std::endl;
	filename << "               ;%;      %;        ;%;        % ;%;  ,%;'" << std::endl;
	filename << "                `%;.     ;%;     %;'         `;%%;.%;'" << std::endl;
	filename << "                 `:;%.    ;%%. %@;        %; ;@%;%'" << std::endl;
	filename << "                    `:%;.  :;bd%;          %;@%;'" << std::endl;
	filename << "                      `@%:.  :;%.         ;@@%;'" << std::endl;
	filename << "                        `@%.  `;@%.      ;@@%;" << std::endl;
	filename << "                          `@%%. `@%%    ;@@%;" << std::endl;
	filename << "                            ;@%. :@%%  %@@%;" << std::endl;
	filename << "                              %@bd%%%bd%%:;" << std::endl;
	filename << "                                #@%%%%%:;;" << std::endl;
	filename << "                                %@@%%%::;" << std::endl;
	filename << "                                %@@@%(o);  . '" << std::endl;
	filename << "                                %@@@o%;:(.,'" << std::endl;
	filename << "                            `.. %@@@o%::;" << std::endl;
	filename << "                               `)@@@o%::;" << std::endl;
	filename << "                                %@@(o)::;" << std::endl;
	filename << "                               .%@@@@%::;" << std::endl;
	filename << "                               ;%@@@@%::;." << std::endl;
	filename << "                              ;%@@@@%%:;;;." << std::endl;
	filename << "                          ...;%@@@@@%%:;;;;,.." << std::endl;
	filename.close();
}

ShrubberyCreationForm::~ShrubberyCreationForm(){
}
