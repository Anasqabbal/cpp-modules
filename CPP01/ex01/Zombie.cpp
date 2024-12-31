#include "Zombie.hpp"

void Zombie::announce( void )
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::set(std::string name)
{
    this->name = name;
}

Zombie::Zombie(void)
{
    name = "def";
}

Zombie::~Zombie(void)
{
    std::cout << "done with: " << name << std::endl;
}