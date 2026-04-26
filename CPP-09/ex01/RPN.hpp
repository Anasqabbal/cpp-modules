#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>


class RPN
{
	private:
		std::stack<int> numbers;

	public:
	RPN();
	~RPN();
	RPN(const RPN &obj);
	RPN &operator=(const RPN &obj);

	void calculate(const std::string &str);
	void PrintRes(void);
};


# endif