#include <iostream>
#include <fstream>
#include "Bureaucrat.hpp"


int main()
{
    /*
    work with grade here you can test
    - grade too high
    - grade too low
    - increment and decrement last grade
    */



   /* grade too high */
    try
    {
        Bureaucrat b("Anas", 1);
        std::cout << b << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }


    /* grade too low */
    try
    {
        Bureaucrat b("Anas", 150);
        std::cout << b << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    
    
    /* increment to too low grade */
    try
    {
        Bureaucrat b("Anas", 1);
        b.IncrementGrade();
        std::cout << b << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    
    
    /* Decrement to too high grade */
    try
    {
        Bureaucrat b("Anas", 1);
        b.IncrementGrade();
        std::cout << b << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}