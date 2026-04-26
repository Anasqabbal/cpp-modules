#include "Fixed.hpp"
#include <sstream>
#include <string>
const int Fixed::nfb = 8;

Fixed::Fixed(const Fixed &fpv)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fpv;
}

Fixed::Fixed(void)
{
	std::cout << "Defaul constructor called" << std::endl;
	fpv = 0;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

void Fixed::operator=(const Fixed &ob1)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (&ob1.fpv != &this->fpv)
		fpv = ob1.getRawBits();
}

Fixed::Fixed(const int number)
{
	std::cout << "Int constructor called" << std::endl;
	fpv = number << nfb;
}

Fixed::Fixed(const float number)
{
	std::cout << "Here" << std::endl;
	fpv = roundf(number * (1 << nfb));
}

int	Fixed::toInt(void) const
{
	return (fpv >> nfb);
}

float Fixed::toFloat(void) const
{
    return (float(fpv) / (1 << nfb));
}

std::ostream &operator<< (std::ostream &output, const Fixed &obj)
{
	output << obj.toFloat();
	return (output);
}

int Fixed::getRawBits( void ) const
{
	return (fpv);
}

void Fixed::setRawBits( int const raw )
{
	fpv = raw;
}
