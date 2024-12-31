#include "Zombie.hpp"

/*when you use the array dynamic allocation your class must have a default constructor. to initialize the value
for each object.

when you use the array dynamic allocation you can't call a constructor and pass to them some valeu so if you want
to initialize your objects you need to creats some functions that do this job for you.

YOU NEED TO READ MORE ABOUT THIS
*/

Zombie* zombieHorde(int N, std::string name)
{
    Zombie *ptr = new Zombie[N];
    if (!ptr)
        return (delete[] ptr, ptr = NULL, ptr);
    for (int i = 0; i < N ; i++)
        ptr[i].set(name);
    return (ptr);
}