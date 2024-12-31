#include <iostream>

int find_and_replace(std::string &org, std::string s1, std::string s2, std::string &newone)
{
    unsigned long long index;
    unsigned long long i;

    index = org.find(s1);
    if (index == ULLONG_MAX)
        return (-1);           
    else
    {
        org.erase(index, s1.size());
        org.insert(index, s2);
        for (i = 0; (i) < index + s1.size(); i++) 
            newone += org[i];
        org = org.substr(index + s1.size());
    }
    return (index);
}

void    get_correct_name(std::string &old)
{
    old += ".replace";
}