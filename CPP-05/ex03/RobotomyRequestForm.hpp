#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm 
{
    private:
		std::string target;
    public:
        RobotomyRequestForm(void);
        ~RobotomyRequestForm(void);
        RobotomyRequestForm (const RobotomyRequestForm &obj);
        RobotomyRequestForm &operator=(const RobotomyRequestForm &obj);


		RobotomyRequestForm(const std::string &target);
		void execute(Bureaucrat const & executor) const;

    };
#endif
