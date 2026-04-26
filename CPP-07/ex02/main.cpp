#include <iostream>
#include "Array.hpp"
#include <vector>

#define MAX_VAL 750

int main(int, char**)
{
    Array<int> numbers(MAX_VAL);

    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }

    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//


    Array<std::vector<int> > strArr(3);
    Array<float> EmptyStr;

    Array< std::vector<int> > arr(3);

    for (unsigned int i = 0; i < arr.size(); ++i) 
    {
        arr[i].push_back(1);
    }

    // Print contents
    for (unsigned int i = 0; i < arr.size(); ++i)
     {
        std::cout << "vector number: " << i << " content: ";
        for (unsigned int j = 0; j < arr[i].size(); ++j)
            std::cout << arr[i][j] << " ";
        std::cout << std::endl;
    }
    return 0;
}