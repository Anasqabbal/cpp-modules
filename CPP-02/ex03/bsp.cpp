#include "Point.hpp"

float my_sqrt(float number)
{
    if (number == 0)
        return (0);
    else if (number < 0)
        return (NAN);
    else if (number == INFINITY)
        return (INFINITY);
	
    float res, x2;
	float half(1.0f / 2.0f);
    float infi;
	
	x2 = number - 1;

	res = half * (x2 + (number / x2));
	while(1)
	{
		float res2(res * res);
		if (roundf(res2) > number)
		{
			x2 = res;
            infi = res;
			res = half * (x2 + (number / x2));
            if (res == infi)
                break ;
		}
		else
			break ;
	}
	return (res);
}

float my_abs(float num)
{
    if (num < 0)
        return (num * -1);
    else
        return (num);
}

float my_pow2(float res)
{
    return (res * res);
}

float three_sides_formula(Point  a, Point  b, Point  c)
{


    Fixed y1, y2, y3;
    Fixed x1, x2, x3;

    y1 = a.get_y_value();
    y2 = b.get_y_value();
    y3 = c.get_y_value();
    x1 = a.get_x_value();
    x2 = b.get_x_value();
    x3 = c.get_x_value();

    float p1 = sqrt(my_pow2(((y1.toFloat() - y2.toFloat()))) + my_pow2(x1.toFloat() - x2.toFloat()));
    float p2 = sqrt(my_pow2(y2.toFloat() - y3.toFloat()) + my_pow2(x2.toFloat() - x3.toFloat()));
    float p3 = sqrt(my_pow2(y3.toFloat() - y1.toFloat()) + my_pow2(x3.toFloat() - x1.toFloat()));



    // p1 = 3;
    // p2 = 5;
    // p3 = 4;
    std::cout << "side 1: " << p1 << std::endl;
    // std::cout << sqrtf(my_pow2(((y1.toFloat() - y2.toFloat()))) + my_pow2(x1.toFloat() - x2.toFloat())) << std::endl;
    std::cout << "side 2: " << p2 << std::endl;
    std::cout << "side 3: " << p3 << std::endl;
    float half_per = (p1 + p2 + p3) / 2;

    std::cout << "half perimeter: " << half_per << std::endl;
    // std::cout << "after half_per: " << ((half_per - p1) * ((half_per - p1)) * ((half_per - p1))) << std::endl;
    Fixed val(half_per * ((half_per - p1) * ((half_per - p2)) * ((half_per - p3))));

    std::cout << "VAL: " << val << std::endl;
    return my_sqrt(val.toFloat());
    return (0);
}

bool it_is_at_same_line(Point p1, Point p2, Point p3)
{
    if (p1.get_x_value().toFloat() ==  p3.get_x_value().toFloat() && p2.get_x_value().toFloat() == p3.get_x_value().toFloat())
        return (1);
    else if (p1.get_y_value().toFloat() == p3.get_y_value().toFloat() && p2.get_y_value().toFloat() == p3.get_y_value().toFloat())
        return (1);
    return (0);
}

float base_formula(Point const p1, Point const p2, Point const p3)
{
    return ((p1.get_x_value().toFloat() * (p2.get_y_value().toFloat() - p3.get_y_value().toFloat()) +
                p2.get_x_value().toFloat() * (p3.get_y_value().toFloat() - p1.get_y_value().toFloat()) +
                p3.get_x_value().toFloat() * (p1.get_y_value().toFloat() - p2.get_y_value().toFloat())) / 2.0f);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    /* to find if a given point is inside a triangle or not I chose to follow this method
     1) let's assume that we have theree four triangles, the main triangle, 
        and derived triagles with the given point
     abc
     
     apc
     apb
     bpc

     2) we calculate the area of these triagles
     3) check if the sum of the derived triangles equal the main triagle
    
    */

       //check if the point on edges
    if ((point.get_x_value() == a.get_x_value() && point.get_y_value() == a.get_y_value()))
        return (false);
    else if (point.get_x_value() == b.get_x_value() && point.get_y_value() == b.get_y_value())
        return (false);
    else if (point.get_x_value() == c.get_x_value() && point.get_y_value() == c.get_y_value())
        return (false);

    // check if the point on the vertex
    if (it_is_at_same_line(a, b, point))
        return (false);
    else if (it_is_at_same_line(a, b, point))
        return (false);
    else if (it_is_at_same_line(a, b, point))
        return (false);

   float A1 = my_abs(three_sides_formula(a, b, c));
//    float x1 = (a.get_x_value()).toFloat();
//    float x2 = (b.get_x_value()).toFloat();
//    float x3 = (c.get_x_value()).toFloat();
//    float y1 = (a.get_y_value()).toFloat();
//    float y2 = (b.get_y_value()).toFloat();
//    float y3 = (c.get_y_value()).toFloat();
//    float AA = ((x1 * my_abs(y2 - y3)) + (x2 * my_abs(y3 - y1)) + (x3 * my_abs(y1 - y2))) / 2;

   float A2 = my_abs(three_sides_formula(a, b, point));
   float A3 = my_abs(three_sides_formula(a, point, c));
   float A4 = my_abs(three_sides_formula(point, b, c));

                                        

   std::cout << "AREA: " << A1 << std::endl;
   std::cout << "A2:  " << A2 << std::endl;
   std::cout << "A3: " << A3 << std::endl;
   std::cout << "A4: " << A4 << std::endl;

   if (roundf(A2 + A3 + A4) == roundf(A1))
        std::cout << "INSIDE " <<  std::endl;
    else
        std::cout << "OUTSIDE " << std::endl;
    std::cout << ": " << A2 + A3 + A4 << ": " << A1  << std::endl;
   return (1);

}
