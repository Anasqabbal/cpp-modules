#include <iostream>

int main()
{
    std::string string = "HI THIS IS BRAIN";
    std::string another= "Another Rf";
    std::string *stringPTR = &string;
    std::string &stringREF = string;

    std::cout << "Address of string variable    :" <<  &string    << std::endl;
    std::cout << "Address of stringPTR          :" << stringPTR  << std::endl;
    std::cout << "Address of stringREF          :" << &stringREF << std::endl;

    std::cout <<"Value of string variable      :" << string << std::endl;
    std::cout <<"Value pointed to by stringPTR :" << *stringPTR << std::endl;
    std::cout <<"Value pointed to by stringREF :" << stringREF << std::endl;
}
