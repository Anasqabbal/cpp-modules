#include "ClapTrap.hpp"

int main()
{
    ClapTrap a;
    ClapTrap b("Anas");

    a.attack("l9iirch"); /*to test that there is not energie points left*/
    a.beRepaired(1);
    a.beRepaired(1);
    a.attack("l9iirch");
    b.attack("l9iirch");
    a.attack("l9iirch");
    a.attack("l9iirch");
    a.attack("l9iirch");
    a.attack("l9iirch");
    a.attack("l9iirch");
    a.attack("l9iirch");
    a.attack("l9iirch");
}