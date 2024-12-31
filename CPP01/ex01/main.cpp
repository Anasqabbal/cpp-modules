#include "Zombie.hpp"

int main()
{
    std::string s = "nothing";
    int size;

    size = 9;
    Zombie *p = zombieHorde(size, s);
    if (!p)
        return (1);
    for (int i = 0; i < size; i++)
        p[i].announce();
    delete[] p;
}