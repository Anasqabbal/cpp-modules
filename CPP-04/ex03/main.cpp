#include "AMateria.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "Character.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include <iostream>

int main()
{

    // /*test clone member functions */
    //     /*Cure*/
    //     AMateria *obj = new Cure();
    //     AMateria *ptr = obj->clone();
    //     std::cout << obj->getType() << std::endl;
    //     std::cout << ptr->getType() << std::endl;
    //     /*Ice*/
    //     AMateria *obj = new Ice();
    //     AMateria *ptr = obj->clone();
    //     std::cout << obj->getType() << std::endl;
    //     std::cout << ptr->getType() << std::endl;
    // delete obj;
    // delete ptr;

    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter* bob = new Character("bob");

    ICharacter* me = new Character("me"); /*still reachable*/
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);

    tmp = src->createMateria("cure");
    me->equip(tmp);
    me->use(0, *bob);
    me->use(1, *bob);

    /* using use function with out index */
    me->use(3, *bob);
    me->use(4, *bob);


    /*test equip more than 4 */
        me->equip(tmp);
        me->equip(tmp);
        me->equip(tmp);
        me->equip(tmp);

        // std::cout << "AFTER unequip" << std::endl;
        // me->unequip(1);
        me->equip(tmp);
        me->equip(tmp);
        me->equip(tmp);


    delete src;
    delete bob;
    delete me;
}
