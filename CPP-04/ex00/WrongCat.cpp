#include "WrongCat.hpp"

WrongCat::WrongCat(void)
{
    std::cout << "WrongCat Defaul Constructor called" << std::endl;
    type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &obj) : WrongAnimal()
{
    std::cout << "WrongCat Copy Constructor called" << std::endl;
    WrongAnimal::operator=(obj);
}

WrongCat &WrongCat::operator=(const WrongCat &obj)
{
    std::cout << "WrongCat copy assignment operator called" << std::endl;
    if (this == &obj)
        return (*this);
    WrongAnimal::operator=(obj);
    return (*this);
}

WrongCat::~WrongCat(void)
{
    std::cout << "WrongCat    Destructor called" << std::endl;
}

void WrongCat::makeSound(void) const
{
    std::cout << "WrongCat: Meow" << std::endl;
}