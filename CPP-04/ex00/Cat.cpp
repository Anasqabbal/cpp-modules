#include "Cat.hpp"

Cat::Cat(void)
{
    std::cout << "Cat    Default Constructor called" << std::endl;
    type = "Cat";
}

Cat::Cat(const Cat &obj) : Animal()
{
    std::cout << "Cat    Copy Constructor called" << std::endl;
    Animal::operator=(obj);
}

Cat &Cat::operator=(const Cat &obj)
{
    std::cout << "Cat    copy assignment operator called" << std::endl;
    if (this == &obj)
        return (*this);
    Animal::operator=(obj);
    return (*this);
}

Cat::~Cat(void)
{
    std::cout << "Cat    Destructor called" << std::endl;
}

void Cat::makeSound(void) const
{
    std::cout << "Cat: Meow" << std::endl;
}
