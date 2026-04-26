#include "Brain.hpp"

Brain::Brain(void)
{
    std::cout << "Brain  Defaul Constructor called" << std::endl;
    for (int i = 0; i < 100; i++)
        ideas[i] = "";
}

Brain::Brain(const Brain &obj)
{
    std::cout << "Brain  Copy Constructor called" << std::endl;
    *this = obj;
}

Brain &Brain::operator=(const Brain &obj)
{
    std::cout << "Brain  Copy assignment operator called" << std::endl;
    if (this == &obj)
        return (*this);
    for (int i = 0; i < 100; i++)
        this->ideas[i] = obj.ideas[i];
    return (*this);
}

Brain::~Brain(void)
{
    std::cout << "Brain  Destructor called" << std::endl;
}

std::string Brain::getIdea(int index)
{
    if (index < 0 || index > 99)
        return NULL;
    return ideas[index];
}

void    Brain::setIdea(int index, std::string val)
{
    if (index < 0 || index > 99)
        return ;
    ideas[index] = val;
}