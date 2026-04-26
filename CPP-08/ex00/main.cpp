#include "easyfind.hpp"
#include <vector>
#include <map>
#include <list>
#include <deque>


int main()
{
    std::vector<int> vec;

    vec.push_back(6);

    std::cout << "Test Vector container" << std::endl;
    std::cout << "the element that you search for, ";
    if (easyfind(vec, 7) == 7)
        std::cout << " is in your container" << std::endl;
    else
        std::cout << "is not in the your container" << std::endl;

    std::cout << "the element that you search for, ";
    if (easyfind(vec, 6) == 6)
        std::cout << "is in your container" << std::endl;
    else
        std::cout << "is not in the your container" << std::endl;


    std::cout << "Test List" << std::endl;
    std::list<int> list;
    list.push_back(1);
    list.push_back(4);
    list.push_back(2);
    list.push_back(7);

    std::cout << "the element that you search for: ";
    if (easyfind(list, 1) == 1)
        std::cout << "is in your container" << std::endl;
    else
        std::cout << "is not in the your container" << std::endl;


    std::cout << "Test deque" << std::endl;
    std::deque<int> deque;
    deque.push_back(1);
    deque.push_back(2);
    deque.push_back(178);
    deque.push_back(9);

    std::cout << "the element that you search for: ";
    if (easyfind(deque, 9) == 9)
        std::cout << "is in your container" << std::endl;
    else
        std::cout << "is not in the your container" << std::endl;

}