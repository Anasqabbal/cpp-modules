#include <iostream>
#include <climits>

int find_and_replace(std::string &org, std::string s1, std::string s2, std::string &newone )
{
    unsigned long long index;

    index = org.find(s1);
    if (index == org.npos)
    {
        newone += org;
        return (-1);
    }       
    else
    {
        std::string first;

        first = org.substr(0, index);
        first += s2;
        org = org.substr(index + s1.size());
        newone += first;
    }
    return (index);
}