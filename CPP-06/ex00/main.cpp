#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
    if (ac < 2 || ac > 2)
        return std::cerr << "Invalid argument number" << std::endl, 1;

    ScalarConverter::convert(av[1]);
}