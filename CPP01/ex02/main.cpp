#include <iostream>

/*
    PTR vs REF in C++

>>>REF: is an aliase for an existing var (is another name for an existing var). Once a ref is initialized to a variable it cannot be changed
        you cannot change the address that is holded by the ref directly, unlike the pointer.
        once the reference initialized to one variable it cannot be changed to reference to another one. unlike the pointer you can change the address
        hence pointing to another one.
        when passong by the reference to another function, you can interact directly with the original variable
        - the reference itseld doesn't have an address bcs it only exists conceptuall, not physically.

        -using the reference can make external code to modify the private member of your class inderctily by returning
        a reference member to your code from  methods in your class;

*/

int main()
{
    std::string string = "HI THIS IS BRAIN";
    std::string another= "Another Rf";
    std::string *stringPTR = &string;
    std::string &stringREF = string;

    std::cout << "the memory address of string variable: " << &string << std::endl;
    std::cout << "the memory address held by stringPTR:  " << stringPTR << std::endl;
    std::cout << "The memory address held by stringREF:  " << &stringREF << std::endl;

    std::cout <<"the value of the string variable: " << string << std::endl;
    std::cout <<"the value pointed to by stringPTR: " << *stringPTR << std::endl;
    std::cout <<"the value pointed to by stringREF: " << stringREF << std::endl;
}
