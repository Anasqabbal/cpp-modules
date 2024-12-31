#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap{
private:
    std::string name;
    int         HitPoints;
    int         EnePoints;
    int         AttPoints;

public:
    ClapTrap(void);
    ClapTrap(std::string name);
    ~ClapTrap(void);
    void    operator=(const ClapTrap &obj);
    void attack(const std::string& target);
    void beRepaired(unsigned int amount);
    void takeDamage(unsigned int amount);
};

#endif