#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie
{
private :
    std::string name;
public :
    void set(std::string nam);
    void announce( void );
    Zombie(void);
    ~Zombie(void);
};

Zombie* zombieHorde( int N, std::string name );

#endif