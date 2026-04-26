#include "AForm.hpp"
// #include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"



int main()
{
	ShrubberyCreationForm sh("home"); /*145, 137*/
	RobotomyRequestForm rb("Robot"); /*72, 45*/
	PresidentialPardonForm pr("SomeWhere"); /*25, 5*/

	AForm *form = &sh;

	try
	{
		Bureaucrat b1("Bur1", 4); /* valid value for bureaucrat */
		Bureaucrat b2("Bur2", 137); /* low than the value that is required in the subject */
		// form->ToCheck(b1);
		// form->execute(b1);
		
		form = &rb;
		(void) form;
		

		/* invalid grade in Bureaucrate 2 */
		// form->ToCheck(b2); 
		// form->execute(b2);

		/* valid values in Bureaucrate 3*/
		// Bureaucrat b3("Bur3", 45); /* low than the value that is required in the subject */
		// form->ToCheck(b3);
		// form->execute(b3);

		b1.executeForm(sh);
		b1.executeForm(rb);

	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}