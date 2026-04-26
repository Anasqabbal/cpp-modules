#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>

template <typename T>
int easyfind(T &container, int ToFind)
{
    typename T::iterator begin = container.begin();
    typename T::iterator end = container.end();

    if (container.end() == std::find(begin, end, ToFind))
        return ToFind + 1;
    return ToFind;
}
#endif