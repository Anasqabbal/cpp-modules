#include "Animal.hpp"

Animal::Animal(void)
{
    std::cout << "Animal Default Constructor called" << std::endl;
    type = "empty";
}

Animal::Animal(const Animal &obj)
{
    std::cout << "Animal Copy Constructor called" << std::endl;
    *this = obj;
}

Animal &Animal::operator=(const Animal &obj)
{
    std::cout << "Animal: Copy assignment operator called" << std::endl;
    if (this == &obj)
        return (*this);
    this->type = obj.type;
    return (*this);
}

Animal::~Animal(void)
{
    std::cout << "Animal Destructor called" << std::endl;
}

std::string Animal::getType(void) const
{
    return (type);
}
void    Animal::makeSound(void) const
{
    std::cout << "Animal: Specify which sound you'de like to hear" << std::endl;
}
