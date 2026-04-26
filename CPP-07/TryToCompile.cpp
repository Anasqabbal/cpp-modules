
#include <iostream>
#include "./ex02/Array.hpp"

int main(int ac, char **av)
{
    (void) ac;
    (void) av;

    int *a = new int();
    Array<int> test(5);

    std::cout << test[10] << std::endl;

    std::cout<< "the program runned successful" << std::endl;
    
    std::cout << "after *a " << std::endl;
}