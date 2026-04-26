#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed{
private :
    int fpv;
    static const int nfb;
public :

    Fixed(const Fixed &fpv);
    Fixed(void);
    void    operator=(const Fixed &ob1);
    ~Fixed(void);
    int     getRawBits( void ) const;
    void    setRawBits( int const raw );
    Fixed(const int number);
    Fixed(const float number);
    int	toInt(void) const;
    float toFloat(void) const;

    bool operator==(const Fixed& b) const;
    bool operator!=(const Fixed& b) const;
    bool operator<(const Fixed& b) const;
    bool operator>(const Fixed& b) const;
    bool operator>=(const Fixed& b) const;
    bool operator<=(const Fixed& b) const;

    Fixed   operator*(const Fixed& b) const;
    Fixed   operator-(const Fixed& b) const;
    Fixed   operator+(const Fixed& b) const;
    Fixed   operator/(const Fixed& b) const;

    Fixed   operator++();
    Fixed   operator++(int);
    Fixed   operator--();
    Fixed   operator--(int);
    
    static Fixed			&min(Fixed &nb1, Fixed &nb2);
    const static Fixed		&min(const Fixed &nb1, const Fixed &nb2);
    static Fixed			&max(Fixed &nb1, Fixed &nb2);
    const static Fixed		&max(const Fixed &nb1, const Fixed &nb2);
     /* the additionnal of const in return type 
	of your function, and specific when you are returning a reference to one of them, 
	
	imagine with me you're you pass a variable with type const and your function must returns a reference if you
	try to return that variable that you pass, and its return type is not const, that's means you can modify this variable
	in another scope, and this breaks const promise. this will leads to indirect modifiying the object.
	
	*/
};

std::ostream &operator<< (std::ostream &output, const Fixed &obj);

#endif