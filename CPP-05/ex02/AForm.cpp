#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(void) : name(""), ToSign(150), ToExec(150)
{
    ItIsSigned = false;
}

AForm::~AForm()
{
}

AForm::AForm(const AForm &obj) : name(obj.name), ToSign(obj.ToSign), ToExec(obj.ToExec)
{
    ItIsSigned = obj.ItIsSigned;
}

AForm &AForm::operator=(const AForm &obj)
{
	if (this == &obj)
		return (*this);
	this->ItIsSigned = obj.ItIsSigned;
	return (*this);
}

int AForm::PreCheck(int val)
{
    if (val > 150)
    {
       throw GradeTooLowException();
    }
    else if (val < 1)
    {
        throw GradeTooHighException();
    }
	return (val);
}

AForm::AForm(const std::string &name, const bool &ItIsSigned, const int &Tosign, const int &Toexec) : name(name),
    ItIsSigned(ItIsSigned)
    , ToSign(PreCheck(Tosign))
    , ToExec(PreCheck(Toexec))
{
}


const std::string	&AForm::getName()        const{return name;}
const bool 			&AForm::getItIsSigned()  const{return ItIsSigned;}
const int			&AForm::getToSign()      const{return ToSign;}
const int			&AForm::getToExec()      const{return ToExec;}


std::ostream &operator<<(std::ostream &os, const AForm &obj1)
{
	os << "Form Name        : " << obj1.getName() << std::endl;
    if (obj1.getItIsSigned())
    {
        os << "Status           : " << "Signed" << std::endl;
    }
    else
    {
        os << "Status           : " << "Not Signed" << std::endl;
    }
    os << "the sign grade   : " << obj1.getToSign() << std::endl;
    os << "the Execute grade: " << obj1.getToExec();

	return os;
}

void				AForm::ToCheck(Bureaucrat const &obj)
{
    beSigned(obj);   
}

void AForm::beSigned(const Bureaucrat &bur)
{

	if (bur.getGrade() <= ToSign)
		ItIsSigned = true;
	else
		throw GradeTooLowException();
}