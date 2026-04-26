#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <ostream>
#include <exception>
#include "Bureaucrat.hpp"


class Bureaucrat;

class Form{
	private:
		std::string const name;
		bool        ItIsSigned;
		const int   ToSign;
		const int   ToExec;
	public:
		Form(void);
		~Form(void);
		Form (const Form &obj);
		Form &operator=(const Form &obj);

		Form(const std::string &name, const bool &IsIsSigned, const int &Tosign, const int &Toexec);
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
	};

std::ostream &operator<<(std::ostream &os, const Form &obj1);
#endif
