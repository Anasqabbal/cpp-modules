#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <deque>
#include <stack>
#include <list>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
    MutantStack(){} 
    ~MutantStack(){}
    MutantStack(MutantStack<T>& obj){(void) obj;}
    MutantStack<T>& operator=(MutantStack<T>& obj){return obj;}

    typedef typename std::deque<T>::iterator iterator ;
    iterator    begin(){return this->c.begin();}
    iterator    end(){return this->c.end();}
};

#endif