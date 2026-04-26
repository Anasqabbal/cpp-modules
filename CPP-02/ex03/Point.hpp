#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"
#include <cmath>

class Point
{
private:
    const Fixed x;
    const Fixed y;
public :
    Point(void);
    Point(const Point &obj);
    Point(float xx, float yy);
    ~Point(void);
    Fixed   get_x_value(void) const;
    Fixed   get_y_value(void) const ;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);
float my_sqrt(float number);
float my_abs(float num);

#endif