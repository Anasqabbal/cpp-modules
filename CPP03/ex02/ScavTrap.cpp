#include "ScavTrap.hpp"


ScavTrap::ScavTrap(std::string name)
{
    std::cout << "ScavTrap Paremeterized Constructor called" << std::endl;
    this->name = name;
    EnePoints = 50;
    AttDmg = 20;
}

ScavTrap::ScavTrap(void)
{
    std::cout << "ScavTrap Default Constructor called" << std::endl; 
    name = "Default";
    EnePoints = 50;
    AttDmg = 20;
}

ScavTrap::~ScavTrap(void)
{
    std::cout << "ScavTrap Destructor called" << std::endl;
}

void    ScavTrap::operator=(const ScavTrap &obj)
{
    if (&obj == this)
        return ;
    this->AttDmg = obj.AttDmg;
    this->HitPoints = obj.HitPoints;
    this->EnePoints = obj.EnePoints;
    this->name = obj.name;
}

void ScavTrap::attack(const std::string& target)
{
    if (EnePoints <= 0 || HitPoints <= 0)
    {
        std::cout << "Energy points is not enough" << std::endl;
        return ;
    }
    std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << 1 << " points of damage!" << std::endl;
    EnePoints--;
    HitPoints--;
    AttDmg++;
}

void ScavTrap::guardGate(void)
{
    std::cout << "ScavTrap in Gate keeper mode" << std::endl;
}