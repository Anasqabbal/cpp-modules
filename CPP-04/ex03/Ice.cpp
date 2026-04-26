#include "Ice.hpp"

Ice::Ice(void) : AMateria("ice"){}

Ice::~Ice(void){}

Ice::Ice(const Ice &obj) : AMateria("ice")
{
    AMateria::operator=(obj);
}

Ice &Ice::operator=(const Ice &obj)
{
    if (this == &obj)
        return (*this);
    AMateria::operator=(obj);
    return (*this);
}

AMateria* Ice::clone(void) const
{
    AMateria *ptr = new Ice();
    return (ptr);
}

std::string const & Ice::getType() const
{
    return (type);
}

void Ice::use(ICharacter &target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}