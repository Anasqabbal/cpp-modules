#include "BitcoinExchange.hpp"


int main(int ac, char **av)
{
    if (ac != 2)
        return std::cout << "Invalid Argument numbers" << std::endl, 1;

    BitcoinExchange btc(av[1]);
	return 0;
}