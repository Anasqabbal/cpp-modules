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
    void    operator =(const Fixed &ob1);
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

    Fixed   operator++();
    Fixed   operator++(int);
    Fixed   operator*(const Fixed& b) const;
};

std::ostream &operator<< (std::ostream &output, const Fixed &obj);

#endif