#include "Intern.hpp"

Intern::Intern(void)
{
}

Intern::~Intern()
{
}

Intern::Intern(const Intern &obj)
{
    (void) obj;
}

Intern &Intern::operator=(const Intern &obj)
{
    (void)obj;
    return (*this);
}

AForm* Intern::CreatRobotomy(const std::string  &tar)
{
    AForm *ptr;
    ptr = new RobotomyRequestForm(tar);
    return ptr;
};

AForm* Intern::CreatShrubbery(const std::string  &tar)
{
    AForm *ptr;

    ptr = new ShrubberyCreationForm(tar);
    return ptr;
};

AForm *Intern::CreatPresidential(const std::string &tar)
{
    AForm *ptr;
    ptr = new PresidentialPardonForm(tar);
    return ptr;
};

AForm *Intern::makeForm(std::string FormName, std::string TheTarget)
{
    Intern ptr;
    AForm * ptr1 = NULL;
    AForm* (Intern::*Creatforms[3])(const std::string &);

    Creatforms[0] = &Intern::CreatShrubbery;
    Creatforms[1] = &Intern::CreatRobotomy;
    Creatforms[2] = &Intern::CreatPresidential;

    std::string Savedforms[3];
    Savedforms[0] = "shrubbery creation";
    Savedforms[1] = "robotomy request";
    Savedforms[2] =  "presidential pardon";

    int i = -1;
    for (i = 0; i < 3; i++)
    {
        if (FormName == Savedforms[i])
            break ;
    }

    try
    {
        switch (i)
        {
            case 0:
            {
                ptr1 =  (ptr.*Creatforms[i])(TheTarget);
                std::cout << "Intern creates " << FormName << std::endl;
                break;
            }
            case 1:
            {
                ptr1 =  (ptr.*Creatforms[i])(TheTarget);
                std::cout << "Intern creates " << FormName << std::endl;
                break ;
            }
            case 2:
            {
                ptr1 =  (ptr.*Creatforms[i])(TheTarget);
                std::cout << "Intern creates " << FormName << std::endl;
                break ;
            }
            default:
            {
                throw "invalid form name";
                break;
            }
        }
        return ptr1;
    }
    catch (const std::exception &e)
    {
        std::cout << "can't create the form cause of ";
        throw;
    }
}

