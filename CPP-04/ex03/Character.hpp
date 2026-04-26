#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#ifndef CH_UNEQUI
#define CH_UNEQUI 10000
#endif


class Character : public ICharacter
{
protected:
    std::string name;
    int         i;
    int         mtrs[4];
    AMateria    *mtr[4];
    AMateria    *on_floor[CH_UNEQUI];
    int         ofi;
public:
    Character(void);
    Character(const Character &obj);
    Character &operator=(const Character &obj);
    ~Character(void);
    Character(const std::string &name);

    std::string const & getName() const;
    void equip(AMateria* m);
    void unequip(int idx);
    void use(int idx, ICharacter& target);
};

#endif