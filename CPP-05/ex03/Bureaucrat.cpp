#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : name("")
{
	grade = 150;
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat::Bureaucrat(const std::string &name, const int &grade) : name(name)
{
		if (grade < 1)
			throw GradeTooHighException();
		else if  (grade > 150)
			throw GradeTooLowException();
		this->grade = grade;
		
}


Bureaucrat::Bureaucrat(const Bureaucrat &obj) : grade(obj.grade)
{
	this->grade = obj.grade;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &obj)
{
	if (this == &obj)
		return (*this);
	this->grade = obj.grade;
	return (*this);
}


const std::string	&Bureaucrat::getName() const
{return name;}

const int			&Bureaucrat::getGrade() const
{return grade;}

void				Bureaucrat::IncrementGrade()
{ 
	if (grade  - 1 < 1)
		throw GradeTooHighException();
	grade--;
}

void				Bureaucrat::DecrementGrade()
{
	if (grade  + 1 > 150)
		throw GradeTooLowException();
	grade++;
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &obj)
{
	os << obj.getName() << ", bureaucrat grade " << obj.getGrade() << "."; 
 	return os;
}

void	Bureaucrat::signForm(Form &form)
{
	try
	{
		if (grade > form.getToExec())
			throw Form::GradeTooLowException();
		form.beSigned(*this);
		std::cout << name << " signed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << name << " could't sign " << form.getName() << " because ";
		throw;
	}

}

void Bureaucrat::executeForm(AForm const & form)
{
	try
	{
		if (grade > form.getToExec())
        	throw GradeTooLowException(); 
		form.execute(*this);
		std::cout << name << " execute " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << name + " can't execute the form \"" + form.getName() + "\" cause of ";
		throw;
	}
}