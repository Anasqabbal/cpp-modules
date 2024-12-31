#include <iostream>
#include "Harl.hpp"

int main(int ac, char **av)
{
    char arr[5][8] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    Harl harl;
    std::string str;
    int    check = 0;

    check = (ac == 2);
    switch (check)
    {
        case 1:
            str = av[1];
            int i;
            check = 1;
            for (i = 0; (check) && (i < 4); (i++))
                check = str.compare(arr[i]);
            i--;
            while (i < 4 && !check)
            {
                std::cout << "[ " << arr[i] << " ]" << std::endl;
                switch (i)
                {
                    case 0:
                        harl.complain("DEBUG");
                        std::cout << std::endl;
                        break;
                    case 1:
                        harl.complain("INFO");
                        std::cout << std::endl;
                        break;
                    case 2:
                        harl.complain("WARNING");
                        std::cout << std::endl;
                        break;
                    default :
                        harl.complain("ERROR");
                        break;
                }
                i++;
            }
            break;
        default :
            return (0);
            break;
    }
}