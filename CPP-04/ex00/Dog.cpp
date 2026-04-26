#include "Dog.hpp"

Dog::Dog(void)
{
    std::cout << "Dog    Default Constructor called" << std::endl;
    type = "Dog";
}

Dog::Dog(const Dog &obj) : Animal()
{
    std::cout << "Dog    Copy Constructor called" << std::endl;
    Animal::operator=(obj);
}

Dog &Dog::operator=(const Dog &obj)
{
    std::cout << "Dog    copy assignment operator called" << std::endl;
    if (this == &obj)
        return (*this);
    Animal::operator=(obj);
    return (*this);
}

Dog::~Dog(void)
{
    std::cout << "Dog    Destructor called" << std::endl;
}
void Dog::makeSound(void) const
{
    std::cout << "Dog: Bark" << std::endl;
}