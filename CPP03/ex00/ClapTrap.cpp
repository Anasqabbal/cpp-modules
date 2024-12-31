#include "ClapTrap.hpp"

void ClapTrap::operator=(const ClapTrap &obj)
{
    if (&obj != &(*this))
    {
        this->name = obj.name;
        this->AttPoints = obj.AttPoints;
        this->HitPoints = obj.HitPoints;
        this->EnePoints = obj.EnePoints;
    }
}

ClapTrap::ClapTrap(void)
{
    std::cout << "Default Constructor called" << std::endl;
    this->name = "default";
    EnePoints = 10;
    HitPoints = 10;
    AttPoints = 0;
}

ClapTrap::ClapTrap(std::string name)
{
    std::cout << "Parameterized Constructor called" << std::endl;
    this->name = name;
    EnePoints = 10;
    HitPoints = 10;
    AttPoints = 0;
}

ClapTrap::~ClapTrap(void)
{
    std::cout << "Destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if (!EnePoints || !HitPoints)
    {
        std::cout << "Energy points is not enough" << std::endl;
        return ;
    }
    std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << 1 << " points of damage!" << std::endl;
    EnePoints--;
    HitPoints--;
    AttPoints++;
}
void ClapTrap::beRepaired(unsigned int amount)
{
    if (!EnePoints || !HitPoints)
    {
        std::cout << "Energy points is not enough" << std::endl;
        return ;
    }
    std::cout << "ClapTrap " << this->name << " repairs " << amount << " of Hit points!" << std::endl;
    HitPoints += amount;
    if (HitPoints > 10)
        HitPoints = 10;
    EnePoints--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    std::cout << "ClapTrap " << this->name << " get damaged " << amount << std::endl;
    HitPoints--;
}