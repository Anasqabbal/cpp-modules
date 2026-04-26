#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
private:
    Brain *ideas;
public :
	Cat(void);
	Cat(const Cat &obj);
	~Cat(void);
	Cat &operator=(const Cat &obj);
	void makeSound(void) const;
}; 

#endif