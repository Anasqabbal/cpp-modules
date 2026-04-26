#include <iostream>

int main(int ac, char **av)
{
    int j;

    if (ac == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    for (int i = 1; i < ac; i++)
    {
        for (j = 0; av[i][j]; j++)
                std::cout.put(std::toupper(av[i][j]));
    }
    std::cout << std::endl;
}
