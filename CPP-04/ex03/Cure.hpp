#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{
public:
    Cure(void);
    Cure(const Cure &obj);
    Cure &operator=(const Cure &obj);
    ~Cure(void);
    std::string const & getType() const;
    AMateria* clone() const;
    void use(ICharacter &target);
};

#endif