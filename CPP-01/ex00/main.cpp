#include "Zombie.hpp"


int main()
{
    /*test newZombie */
        Zombie *z = newZombie("Anas");
        z->announce();
        delete z;

    /* test random Zombie */
        randomChump("Anas");
}