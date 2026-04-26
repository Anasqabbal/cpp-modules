#include "AMateria.hpp"

AMateria::AMateria(std::string const &type)
{
        this->type = type;
}

AMateria::AMateria(void) : type("Default")
{}

AMateria::~AMateria(void)
{}

AMateria::AMateria(const AMateria &obj) : type(obj.type)
{}

AMateria    &AMateria::operator=(const AMateria &obj)
{
    if (this == &obj)
        return (*this);
    this->type = obj.type;
    return (*this);
}

std::string const &AMateria::getType(void) const
{
    return (type);
}

void AMateria::use(ICharacter &target)
{
    (void)target;
}

