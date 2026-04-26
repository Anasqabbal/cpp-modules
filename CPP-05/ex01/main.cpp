#include "Form.hpp"
// #include "Bureaucrat.hpp"



int main()
{

	/* form with valid parameters */
	{
		std::cout << "Test 1:" << std::endl;
		try
		{
			Form test1("form1", false, 10, 10);
			std::cout << "form Created successful" << std::endl;
			std::cout << test1 << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cout << e.what();
		}
		std::cout << std::endl;
		std::cout << std::endl;
	}
	
	/*form with invalid sign grade*/
	{
		std::cout << "Test 2:" << std::endl;
		try
		{
			Form test1("form2", false, 0, 10);
			std::cout << "form Created successful" << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cout << e.what();
		}
		std::cout << std::endl;
		std::cout << std::endl;
	}

	/*form with invalid execute grade*/
	{
		std::cout << "Test 3:" << std::endl;
		try
		{
			Form test1("form2", false, 1, 155);
			std::cout << "form Created successful" << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cout << e.what();
		}
		std::cout << std::endl;
		std::cout << std::endl;
	}


	{
		std::cout << "Test 4:" << std::endl;
		std::cout << "--> From with grade to sign : 10 <--" << std::endl;
		std::cout << "--> Creat Bureaucrate high enough to sign the form like 10 or high <--" << std::endl;
		Form f1("Form1", false, 10, 10);
		Bureaucrat b1("Bureaucrat1", 10);

		std::cout << f1 << std::endl << std::endl;
		std::cout << "Call beSigned: " << std::endl << std::endl;
		f1.beSigned(b1);
		std::cout << f1 << std::endl;
	}


	{
		std::cout << "\n\n--------Test 5:------" << std::endl;
		std::cout << "From with grade to sign : 10" << std::endl;
		std::cout << "--> Creat Bureaucrate with low grade than that is requerid to sign the form like 11 <--" << std::endl;
		Form f1("Form1", false, 8, 10);
		Bureaucrat b1("Bureaucrat1", 10);

		std::cout << "-----form STATUS: " << "----" << std::endl << f1 << std::endl;
		std::cout << "call SignForm() :" << std::endl;
		b1.signForm(f1);
		std::cout << "-----form STATUS: " << "----" << std::endl << f1 << std::endl;
	}
}