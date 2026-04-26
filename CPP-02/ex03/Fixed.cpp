#include "Fixed.hpp"
#include <sstream>
#include <string>
#include <cmath>
const int Fixed::nfb = 8;

Fixed::Fixed(const Fixed &fpv)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = fpv;
}

Fixed::Fixed(void)
{
	// std::cout << "Defaul constructor called" << std::endl;
	fpv = 0;
}

Fixed::~Fixed(void)
{
	// std::cout << "Destructor called" << std::endl;
}

void Fixed::operator=(const Fixed &ob1)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	if (&ob1.fpv != &this->fpv)
		fpv = ob1.getRawBits();
}

Fixed::Fixed(const int number)
{
	// std::cout << "Int constructor called" << std::endl;
	fpv = number << nfb;
}

Fixed::Fixed(const float number)
{
		// fpv = float(roundf(number) * (1 << nfb));
		fpv = roundf(number * 256);
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

/* overload 6 comparison operators */

bool Fixed::operator==(const Fixed& b) const
{
	return (this->fpv == b.fpv);
}
bool Fixed::operator!=(const Fixed& b) const
{
	return (this->fpv != b.fpv);
}
bool Fixed::operator>(const Fixed& b) const
{
	return (this->fpv > b.fpv);
}
bool Fixed::operator<(const Fixed& b) const
{
	return (this->fpv < b.fpv);
}
bool Fixed::operator>=(const Fixed& b) const
{
	return (this->fpv >= b.fpv);
}
bool Fixed::operator<=(const Fixed& b) const
{
	return (this->fpv <= b.fpv);
}

/* the 4 arithmetic operators */
Fixed Fixed::operator*(const Fixed& b) const
{
	return (Fixed(this->toFloat() * b.toFloat()));
}

/*postfix and prefix increment and decrement*/
Fixed Fixed::operator++()
{
	// *this = Fixed((float)(this->toFloat() + pow(2, (nfb * (-1)))));
	++this->fpv;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed o;

	o = *this;
	++this->fpv;
	// *this = Fixed((float)(this->toFloat() + pow(2, (nfb * (-1)))));
	return (o);
}

Fixed Fixed::operator--()
{
	// *this = Fixed((float)(this->toFloat() + pow(2, (nfb * (-1)))));
	--this->fpv;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed o;

	o = *this;
	--this->fpv;
	// *this = Fixed((float)(this->toFloat() + pow(2, (nfb * (-1)))));
	return (o);
}

Fixed Fixed::operator-(const Fixed& b) const
{
	return (Fixed(this->toFloat() - b.toFloat()));
}

Fixed Fixed::operator+(const Fixed &b) const
{
	return (Fixed(this->toFloat() + b.toFloat()));
}

Fixed Fixed::operator/(const Fixed &b) const
{
	return (Fixed(this->toFloat() / b.toFloat()));
}

/* min and max values */
 
Fixed &Fixed::min(Fixed &nb1, Fixed &nb2)
{
	return (nb1.toFloat() < nb2.toFloat() ? nb1 : nb2);
}

const Fixed &Fixed::min(const Fixed &nb1, const Fixed &nb2)
{
	return (nb1.toFloat() < nb2.toFloat() ? nb1 : nb2);
}

Fixed &Fixed::max(Fixed &nb1, Fixed &nb2)
{
	std::cout << "here\n";
	return (nb1.toFloat() > nb2.toFloat() ? nb1 : nb2);
}

const Fixed &Fixed::max(const Fixed &nb1, const Fixed &nb2)
{
	return (nb1.toFloat() > nb2.toFloat() ? nb1 : nb2);
}

