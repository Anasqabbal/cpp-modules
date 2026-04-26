#include "Span.hpp"


int main()
{
    
    try
    {
        // Span num(0) ;// invalid arg
        Span num(10);
    
        num.addNumber(5);
        // num.addNumber(9);
        // num.addNumber(99);
        // num.addNumber(-83);
        // num.addNumber(141);
        // num.addNumber(-140);
        // num.addNumber(-142);
        // num.addNumber(111);

        std::cout << num.shortestSpan() << std::endl;
        std::cout << num.longestSpan() << std::endl;


        std::vector<int> vec;
        vec.push_back(232);
        vec.push_back(34);
        vec.push_back(23);
        vec.push_back(24);
        vec.push_back(-34);
        vec.push_back(5);
        // vec.push_back(5);

        Span num1(6);
        num1.addNumber(vec.begin(), vec.end());
        std::cout << num1.shortestSpan() << std::endl;
        std::cout << num1.longestSpan() << std::endl;

    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}