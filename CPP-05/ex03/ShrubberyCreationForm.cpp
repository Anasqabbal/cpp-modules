#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(void)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &obj): AForm(obj.getName(), obj.getItIsSigned(), obj.getToSign(), obj.getToExec())
{
	this->target = obj.target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreationForm", false, 145, 137)
{
	this->target = target;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &obj)
{
	if (this == &obj)
		return (*this);

	AForm::operator=(obj);
	this->target = obj.target;
	return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const 
{
	(void) executor;
	if (!getItIsSigned())
	{
		 if (executor.getGrade() > getToExec())
     {
		 	  throw GradeTooLowException();
     }
		  std::string FileName = this->target + "_shrubbery";
		  std::ofstream file(FileName.c_str());
			std::string tree1 = "              v .   ._, |_  .,\n\
				`-._\\/  .  \\ /    |/_\n\
					\\  _\\, y | \\//\n\
				_\\_.___\\, \\/ -.\\||\n\
				`7-,--.`._||  / / ,\n\
				/\'     `-. `./ / |/_.\'\n\
							|    |//\n\
							|_    /\n\
							|-   |\n\
							|   =|\n\
							|    |\n\
		--------------------/ ,  . \\--------._\n\n\n\n\n\n";
        std::string tree2 = ".\n\
                                              .         ;\n  \
                 .              .              ;%     ;;   \n\
                   ,           ,                :;%  %;   \n\
                    :         ;                   :;%;'     .,   \n\
           ,.        %;     %;            ;        %;'    ,;\n\
             ;       ;%;  %%;        ,     %;    ;%;    ,%'\n\
              %;       %;%;      ,  ;       %;  ;%;   ,%;' \n\
               ;%;      %;        ;%;        % ;%;  ,%;'\n\
                `%;.     ;%;     %;'         `;%%;.%;'\n\
                 `:;%.    ;%%. %@;        %; ;@%;%'\n\
                    `:%;.  :;bd%;          %;@%;'\n\
                      `@%:.  :;%.         ;@@%;'   \n\
                        `@%.  `;@%.      ;@@%;         \n\
                          `@%%. `@%%    ;@@%;        \n\
                            ;@%. :@%%  %@@%;       \n\
                              %@bd%%%bd%%:;     \n\
                                #@%%%%%:;;\n\
                                %@@%%%::;\n\
                                %@@@%(o);  . \'\n\
                                %@@@o%;:(.,\'  \n\
                            `.. %@@@o%::;     \n\
                               `)@@@o%::;     \n\
                                %@@(o)::;     \n\
                               .%@@@@%::;     \n\
                               ;%@@@@%::;.    \n\
                              ;%@@@@%%:;;;. \n\
                          ...;%@@@@@%%:;;;;,..\n";
			file.write(tree1.c_str(), tree1.size());
			file.write(tree2.c_str(), tree2.size());
			file.close();
	}
}
