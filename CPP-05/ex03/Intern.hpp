#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern{
    private:
    public:
        Intern(void);
        ~Intern(void);
        Intern (const Intern &obj);
        Intern &operator=(const Intern &obj);

        AForm  *CreatRobotomy(const std::string &tar);
        AForm  *CreatShrubbery(const std::string &tar);
        AForm  *CreatPresidential(const std::string &tar);
        AForm   *makeForm(std::string FormName, std::string TheTarget);

    };
#endif
