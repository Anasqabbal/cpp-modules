#include "Fixed.hpp"

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


int Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (fpv);
}
void Fixed::setRawBits( int const raw )
{
    fpv = raw;
}
