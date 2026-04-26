#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void)
{
    std::cout << "WrongAnimal Default Constructor called" << std::endl;
    type = "empty";
}

WrongAnimal::WrongAnimal(const WrongAnimal &obj)
{
    std::cout << "WrongAnimal Copy Constructor called" << std::endl;
    *this = obj;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &obj)
{
    if (this == &obj)
        return (*this);
    this->type = obj.type;
    return (*this);
}

WrongAnimal::~WrongAnimal(void)
{
    std::cout << "WrongAnimal Destructor called" << std::endl;
}

std::string WrongAnimal::getType(void) const
{
    return (type);
}
void    WrongAnimal::makeSound(void) const
{
    std::cout << "WrongAnimal: Specify which sound you'de like to hear" << std::endl;
}