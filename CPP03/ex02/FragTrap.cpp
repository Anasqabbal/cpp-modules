#include "FragTrap.hpp"


FragTrap::FragTrap(std::string name)
{
    std::cout << "FragTrap Paremeterized Constructor called" << std::endl;
    this->name = name;
    EnePoints = 100;
    AttDmg = 30;
}

FragTrap::FragTrap(void)
{
    std::cout << "FragTrap Default Constructor called" << std::endl; 
    name = "Default";
    EnePoints = 100;
    AttDmg = 30;
}

FragTrap::~FragTrap(void)
{
    std::cout << "FragTrap Destructor called" << std::endl;
}

void    FragTrap::operator=(const FragTrap &obj)
{
    this->AttDmg = obj.AttDmg;
    this->EnePoints = obj.EnePoints;
    this->name = obj.name;
}

void FragTrap::attack(const std::string& target)
{
    if (EnePoints <= 0 || HitPoints <= 0)
    {
        std::cout << "Energy points is not enough" << std::endl;
        return ;
    }
    std::cout << "FragTrap " << this->name << " attacks " << target << ", causing " << 1 << " points of damage!" << std::endl;
    EnePoints--;
    HitPoints--;
    AttDmg++;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "highFivesGuys Called" << std::endl;
}