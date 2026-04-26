#include "Cure.hpp"

Cure::Cure(void) : AMateria("cure"){}
Cure::~Cure(void){}
Cure::Cure(const Cure &obj) : AMateria("cure")
{
    AMateria::operator=(obj);
}

Cure &Cure::operator=(const Cure &obj)
{
    if (this == &obj)
        return (*this);
    AMateria::operator=(obj);
    return (*this);
}

AMateria* Cure::clone(void) const
{
    AMateria *ptr = new Cure();
    return (ptr);
}
std::string const & Cure::getType() const
{
    return (type);
}

void Cure::use(ICharacter &target)
{
    std::cout << "* heals " << target.getName() << "\'s wounds *" << std::endl;
}
