#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include "Character.hpp"
#include "AMateria.hpp"

class MateriaSource : public IMateriaSource, public Character
{
protected:
    AMateria *ptr[4];
    int         pi;
public:
    MateriaSource(void);
    ~MateriaSource(void);
    MateriaSource(const MateriaSource &obj);
    MateriaSource &operator=(const MateriaSource &obj);
    void learnMateria(AMateria*);
    AMateria* createMateria(std::string const & type);
};

#endif