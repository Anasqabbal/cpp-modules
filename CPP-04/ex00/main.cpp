#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    const WrongAnimal *me = new WrongAnimal();
    const WrongAnimal *ca = new WrongCat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound();
    j->makeSound();
    meta->makeSound();
    me->makeSound();
    ca->makeSound();

    delete me;
    delete ca;
    delete meta;
    delete i;
    delete j;
    return 0;
}