#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void)
{

}

RobotomyRequestForm::~RobotomyRequestForm()
{

}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &obj) :  AForm(obj.getName(), obj.getItIsSigned(), obj.getToSign(), obj.getToExec())
{
	this->target = obj.target;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("RobotomyRequestForm", false, 72, 45)
{
	this->target = target;
}


RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &obj)
{
	if (this == &obj)
		return (*this);

	AForm::operator=(obj);
	this->target = obj.target;
	return (*this);
}


void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	std::cout << "Zzzzzzz ..." << std::endl;
	if (getToExec() < executor.getGrade())
	{
		std::cout << "Robotomy failed cause: ";
        throw GradeTooLowException(); 
	}
	std::cout << target << " has been robotomized successfully 50% of the time." << std::endl;
}