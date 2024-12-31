#include "Fixed.hpp"
#include <iostream>


int main()
{
	// Fixed const b( 1);
	// Fixed const c( 10 );
	Fixed a(0);
	Fixed const d(Fixed(5.05f) * Fixed( 2 ));


	/* Comparison operators test */

	// if (b > c)
	// 	std::cout << "	b greather than c" << std::endl;
	// else if (b < c)
	// 	std::cout << "	b smaller than c" << std::endl;
	// else if (c == b)
	// 	std::cout << "	c and b are equals" << std::endl;
	// else if (c != b)
	// 	std::cout << "	b is not equal to c" << std::endl;
	// if (a >= b)
	// 	std::cout << "	a greather than or equal to b: " << std::endl;
	// else if (a <= b)
	// 	std::cout << "	a smaller than or equal to b" << std::endl;

	/* Arithmetic operators test */

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << d << std::endl;
}