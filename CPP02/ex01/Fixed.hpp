#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed{
private :
    int fpv;
    static const int nfb;
public :

    Fixed(const Fixed &fpv);
    Fixed(void);
    ~Fixed(void);
    void    operator =(const Fixed &ob1);
    int     getRawBits( void ) const;
    void    setRawBits( int const raw );
    Fixed(const int number);
    Fixed(const float number);
    int	toInt(void) const;
    float toFloat(void) const;
};

std::ostream &operator<< (std::ostream &output, const Fixed &obj);

#endif