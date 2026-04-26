#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class AForm;

class ShrubberyCreationForm : public AForm
{
    private:
		std::string target;
    public:
        ShrubberyCreationForm(void);
        ~ShrubberyCreationForm(void);
        ShrubberyCreationForm (const ShrubberyCreationForm &obj);
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &obj);

		ShrubberyCreationForm(const std::string &target);
		void execute(Bureaucrat const & executor) const;

    };
#endif
