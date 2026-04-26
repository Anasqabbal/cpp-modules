#include "Phonebook.hpp"

int main()
{
    std::string			strl;
    std::string			line;
    PhoneBook  			ph;
    int					index;
    int					flag;
    bool				isnum;

    index = 0;
    ph.set_i_value(-1);
    while(1)
    {
        flag = 0;
        std::cout << "enter one of these commands (ADD, SEARCH, EXIT): " << std::endl;
        std::cout << "> ";
        std::getline(std::cin, strl);
        if (std::cin.eof())
            exit(0);
        if (strl == "ADD")
        {
            ph.add_to_contact(0, ph.get_values(), index);
            ph.add_to_contact(1, ph.get_values(), index);
            ph.add_to_contact(2, ph.get_values(), index);
            ph.add_to_contact(3, ph.get_values(), index);
            ph.add_to_contact(4, ph.get_values(), index);
			ph.set_value_to_index(ph.get_values(), index % 8, index);
	        if (ph.get_i_value() < 7)
                ph.set_i_value(index % 8);
            index++;
            std::cout << std::endl;
        }
        else if (strl == "SEARCH")
        {
			ph.print_all_contacts(ph);
            while(1 && ph.get_i_value() != -1)
            {
                if (!flag)
			        std::cout << "enter index number: ";
                else
                    std::cout << "your index out of the range, try another one: "; 
                std::getline(std::cin, line, '\n');
				if (std::cin.eof())
            		exit(0);
                if (strl.empty())
                    continue ;
                isnum = all_num(line.c_str());
				if (isnum && line.size() == 1 && ph.print_specific_contact(ph, line[0] - 48))
					break ;
                else
                    flag = 1;
            }
        }
        else if (strl == "EXIT")
            exit(0);
    }
    return (0);
}