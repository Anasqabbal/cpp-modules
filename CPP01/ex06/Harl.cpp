
#include "Harl.hpp"
#include <string>

void Harl::debug( void )
{
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}
void Harl::info( void )
{
    std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}
void Harl::warning( void )
{
    std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl;
}
void Harl::error( void )
{
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain( std::string level )
{
    char arr[5][8] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    void (Harl::*ptr) (void);
    int check = 1;

    for (int i = 0; i < 4; i++)
    {
        check = level.compare(arr[i]);
        switch(check)
        {
            case 0 :
                switch (i)
                {
                    case 0:
                        ptr = &Harl::debug;
                        break;
                    case 1:
                        ptr = &Harl::info;
                        break;
                    case 2:
                        ptr = &Harl::warning;
                        break;
                    case 3:
                        ptr = &Harl::error;
                        break;
                }
                (this->*ptr)();
                break;
            default :
                continue;
                break ;
        }
    }
}