#include "HumanB.hpp"
#include "Weapon.hpp"

HumanB::HumanB(std::string name)
{
    this->name = name;
    weapon = NULL;
}

void HumanB::setWeapon(Weapon& club)
{
    weapon = &club;
}

void HumanB::attack(void)
{
    std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}