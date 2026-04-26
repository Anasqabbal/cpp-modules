#include "Fixed.hpp"
#include <iostream>

int main( void ) 
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	return 0;
}
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
		/* + */
			// std::cout << Fixed(1.1f) + Fixed(20.0f) << std::endl;
		/* - */
			// std::cout << Fixed(100.1f) - Fixed(20.0f) << std::endl;
		/* * */
			// std::cout << Fixed(1.0f) * Fixed(20.0f) << std::endl;
		/* / */
			// std::cout << Fixed(1.0f) / Fixed(0) << std::endl;

	/* increment && decrement*/
		/* increment */
			// std::cout << "pre increment: " << ++a << std::endl;
			// std::cout << "post increment:\noldone: " << a++ << "\nnew one: " << a << std::endl;
		/* decrement */
			// std::cout << "pre increment: " << --a << std::endl;
			// std::cout << "post increment:\noldone: " << a-- << "\nnew one: " << a << std::endl;
	
	/*min and max functions*/
		/* min */
			// std::cout << Fixed::min( a, b ) << std::endl;
		/* max */
			// std::cout << Fixed::max( a, b ) << std::endl;