#include <string.h>
#include <stdio.h>
#include <iostream>

int main(int ac, char **av)
{
    std::string arg1 = av[1];
    if (arg1 == "upper")
    {
        for (int i = 0; av[2][i]; i++)
            printf("%c", std::toupper((int)av[2][i]));
    }
    else
    {
        for (int i = 0; av[2][i]; i++)
        {
            if (i == 0)
                printf("%c", std::toupper((int)av[2][i]));
            else if (av[2][i] == '_' && av[2][i + 1] && !isupper(av[2][i + 1]))
            {
                av[2][i + 1] = std::toupper((int)av[2][i + 1]);
                continue;
            }
            else
                printf("%c", av[2][i]);
        }
    }
}