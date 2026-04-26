#include "AForm.hpp"
// #include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"



int main()
{
	Intern someRandomIntern;
	AForm* rrf;
	/*
		shreberry Creation: 145, 137;
		robotomy request: 72, 45;
		presidential pardon 25, 5; 
		
	*/
	

	/* Bureaucrate with high value  that can do all things*/
	try
	{
		/*
			-creat bur with high value;
			-creat bur with low value;
			-creat bur with values can't execute some;
			-try to sign the and execute the form;
		
		*/
		Bureaucrat b1("Bur1", 137); /* valid value for bureaucrat */
		
		// rrf = someRandomIntern.makeForm("robotomy request", "Bender"); //* robotomy request */
		// rrf->execute(b1);
		// delete rrf;

		// rrf = someRandomIntern.makeForm("shrubbery creation", "Bender"); //* shrubbery creation */
		// rrf->execute(b1);
		// delete rrf;

		rrf = someRandomIntern.makeForm("presidential pardon", "Bender"); //* presidential pardon */
		rrf->execute(b1);
		delete rrf;

		rrf = someRandomIntern.makeForm("Nothing", "Bender"); //* presidential pardon */
		rrf->execute(b1);
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (const char * msg)
	{
		std::cout << msg << std::endl;
	}
}