#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
    if (N <= 0)
    {
        std::cout << "the size canno't be less than or equal to zero." << std::endl; 
        return (NULL);
    }
    Zombie *ptr = new Zombie[N];
    for (int i = 0; i < N ; i++)
        ptr[i].set(name);
    return (ptr);
}