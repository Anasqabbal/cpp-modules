#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <ostream>
#include <exception>
#include "Bureaucrat.hpp"

class FormNotSigned :  public std::exception
{
	const char * what()  const throw()
	{
		   return "your form is not signed";
	}
};

class Bureaucrat;

class AForm{
	private:
		std::string const name;
		bool        ItIsSigned;
		const int   ToSign;
		const int   ToExec;
	public:
		AForm(void);
		virtual ~AForm(void);
		AForm (const AForm &obj);
		AForm &operator=(const AForm &obj);

		AForm(const std::string &name, const bool &IsIsSigned, const int &Tosign, const int &Toexec);
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
	
		int	PreCheck(int val);
		
		/* getters */
		const std::string	&getName() const;
		const bool 			&getItIsSigned() const;
		const int			&getToSign() const;
		const int			&getToExec() const;

		void				beSigned(const Bureaucrat &bur);
		void				ToCheck(Bureaucrat const &obj);
		virtual void		execute(Bureaucrat const & executor) const = 0;
	};

std::ostream &operator<<(std::ostream &os, const AForm &obj1);
#endif
