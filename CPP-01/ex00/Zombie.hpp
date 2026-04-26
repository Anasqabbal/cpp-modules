#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie
{
private :
    std::string name;
public :
    void announce( void );
    Zombie(void);
    Zombie(std::string nam);
    ~Zombie(void);
};

Zombie* newZombie(std::string name);
void    randomChump( std::string name );
#endif
