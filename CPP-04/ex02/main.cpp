#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    // const Animal *ptr = new Animal(); // the compiler should returns error
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound();
    j->makeSound();

    delete i;
    delete j;
    return 0;
}