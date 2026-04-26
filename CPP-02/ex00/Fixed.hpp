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
    ~Fixed(void);
    void operator =(const Fixed &ob1);
    int     getRawBits( void ) const;
    void    setRawBits( int const raw );
};

#endif