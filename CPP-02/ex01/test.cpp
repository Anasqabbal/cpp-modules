#include "Fixed.hpp"

void    my_Fucking_float(Fixed a)
{
    int nmb = a.getRawBits();
    int sign = nmb < 0 ? 1 : 0;
    std::string bin;

    for (int i  = 0; i < 31; i++)
        bin += nmb % 2 == 1 ? '1': '0';
    bin += sign < 0 ? '1' : '0';
    
}

int main()
{
    Fixed a(1.34f);

    my_Fucking_float(a);
    std::cout << a << std::endl;
}