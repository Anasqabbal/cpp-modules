#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <ostream>
#include <exception>
#include "AForm.hpp"


class GradeTooLowException :  public std::exception
{
	const char * what()  const throw()
	{
		   return "your grade is too low";
	}
};

class GradeTooHighException :  public std::exception
{
	const char * what()  const throw()
	{
		   return "your grade is too high";
	}
};

class AForm;

class Bureaucrat{
	private:
		const	std::string name;
		int		grade;
	public:
		Bureaucrat(void);
		~Bureaucrat(void);
		Bureaucrat (const Bureaucrat &obj);
		Bureaucrat &operator=(const Bureaucrat &obj);

		Bureaucrat(const std::string &name, const int &grade);
		const std::string	&getName() const;
		const int 			&getGrade() const ;
		void	IncrementGrade();
		void	DecrementGrade();

		void signForm(AForm &form);
		void executeForm(AForm const & form);
	};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &obj);

#endif
