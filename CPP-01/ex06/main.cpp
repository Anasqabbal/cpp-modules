#include <iostream>
#include "Harl.hpp"

int main(int ac, char **av)
{
    char arr[5][8] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    Harl harl;
    std::string str;
    int    check = 0;

    if (ac == 2)
    {
        str = av[1];
        int i;
        check = 1;
        for (i = 0; (check) && (i < 4); (i++))
            check = str.compare(arr[i]);
        std::cout << "[ " << arr[i] << " ]" << std::endl;
        switch (i)
        {
            case 0:
                harl.complain("DEBUG");
            case 1:
                harl.complain("INFO");
            case 2:
                harl.complain("WARNING");
            case 3:
                harl.complain("ERROR");
            default :
                std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
        }
    }
}