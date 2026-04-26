#include "PresidentialPardonForm.hpp"
PresidentialPardonForm::PresidentialPardonForm(void) : AForm("PresidentialPardonForm", false, 25, 5)
{
}
PresidentialPardonForm::~PresidentialPardonForm()
{
}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &obj) : AForm(obj.getName(), obj.getItIsSigned(), obj.getToSign(), obj.getToExec())
{
    this->target = obj.target;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("PresidentialPardonForm", false, 25, 5)
{
	this->target = target;
}
PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &obj)
{
	if (this == &obj)
		return (*this);

	AForm::operator=(obj);
	this->target = obj.target;
	return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (getToExec() < executor.getGrade())
	{
        throw GradeTooLowException(); 
	}
	std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
