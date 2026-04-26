#include "Dog.hpp"

Dog::Dog(void) : Animal()
{
    std::cout << "Dog    Default Constructor called" << std::endl;
    type = "Dog";
    ideas = new Brain();
}

Dog::Dog(const Dog &obj) : Animal()
{
    std::cout << "Dog    Copy Constructor called" << std::endl;
    Animal::operator=(obj);
    Brain *ideass = new Brain();
    *ideass = *(obj.ideas);
    this->ideas = ideass;
}

Dog &Dog::operator=(const Dog &obj)
{
    std::cout << "Dog    copy assignment operator called" << std::endl;
    if (this == &obj)
        return (*this);
    Animal::operator=(obj);
    delete ideas;
    ideas = new Brain(*(obj.ideas));
    return (*this);
}

Dog::~Dog(void)
{
    delete ideas;
    std::cout << "Dog    Destructor called" << std::endl;
}
void Dog::makeSound(void) const
{
    std::cout << "Dog: Bark" << std::endl;
}