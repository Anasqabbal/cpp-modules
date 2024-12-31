#include "HumanA.hpp"
#include "Weapon.hpp"

HumanA::HumanA(std::string name, Weapon &weapon)
:  weapon(weapon), name(name) 
{
}

void HumanA::attack(void)
{
    std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}