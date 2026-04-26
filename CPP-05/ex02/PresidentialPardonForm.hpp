#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    private:
        std::string target;
    public:
        PresidentialPardonForm(void);
        ~PresidentialPardonForm(void);
        PresidentialPardonForm (const PresidentialPardonForm &obj);
        PresidentialPardonForm &operator=(const PresidentialPardonForm &obj);

        PresidentialPardonForm(const std::string &target);
        void execute(Bureaucrat const & executor) const;
    };
#endif
