#include "Point.hpp"


Point::Point(void) : x(0), y(0)
{}

Point::Point(const Point &obj) : x(obj.x), y(obj.y)
{
    //std::cout << "Copy constructor called" << std::endl;
    // this->x = obj.x;
    // this->y = obj.y;
}

Point::Point(float xx, float yy) : x(xx), y(yy)
{
}

// void Point::operator=(const Point &ob1)
// {
// 	// std::cout << "Copy assignment operator called" << std::endl;
// 	x = ob1.x;
// 	y = ob1.y;
// }

Fixed Point::get_x_value(void) const
{
	return (x);
}

Point::~Point(void)
{
	// std::cout << "Destructor called" << std::endl;
}

Fixed Point::get_y_value(void) const
{
	return (y);
}