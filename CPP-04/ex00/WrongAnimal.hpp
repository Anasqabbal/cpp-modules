#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
protected:
    std::string type;
public:
    WrongAnimal(void);
    WrongAnimal(const WrongAnimal &obj);
    ~WrongAnimal(void);
    WrongAnimal &operator=(const WrongAnimal &obj);

    void    makeSound(void) const;
    std::string     getType(void) const;
};

#endif