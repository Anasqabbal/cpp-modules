#include <iostream>

int *PPtest(int &s)
{
    int *p = &s;
    return (p);
}
int main()
{
    int a;

    int *aa;
    a = 9;
    int *p = PPtest(a);
    std::cout << "a value "  << a <<  " a address: " << &a << std::endl;
    std::cout << "*p value " << *p << " p hold: " << p << std::endl;
}