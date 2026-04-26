#include "RPN.hpp"


RPN::RPN(){}
RPN::~RPN(){}
RPN::RPN(const RPN &obj)
{(
	void)obj;
}
RPN &RPN::operator=(const RPN &obj)
{
	(void) obj;
	return *this;
}

void	DoTheCalculation(long &res, char op, int val1, int val2)
{
	if (op == '+')
		res = val1 + val2;
 	else if (op == '-')
		res = val1 - val2;
	else if (op == '*')
		res = val1 * val2;
	else if (op == '/')
	{
		if (val2)
			res = val1 / val2;
		else
		{
			std::cout << "Error : Denominator can't be 0" << std::endl;
			exit (1);
		}
	}
}

void	RPN::calculate(const std::string &str)
{
	for (size_t i = 0; i < str.size(); i++)
	{
		if (str[i] != '+' && str[i] != '-' && str[i] != '/' && str[i] != '*')
		{
			numbers.push(str[i] - 48);
		}
		else
		{
			if (numbers.size() < 2)
			{
				std::cout << "Error" << std::endl;
				exit (1);
			}
			int num1 = numbers.top();
			numbers.pop();

			int num2 = numbers.top();
			numbers.pop();
			long res = 0;

			DoTheCalculation(res, str[i], num2, num1);
			numbers.push(res);
		}
	}
}

void RPN::PrintRes(void)
{
	if (numbers.size() > 1)
	{
		std::cout << "Error " << std::endl;
		exit (1);
	}

	if (numbers.size())
	std::cout << (int)numbers.top() << std::endl;
	numbers.pop();
}