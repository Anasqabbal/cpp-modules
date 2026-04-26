#include "Span.hpp"

class Span::CantFindSpan : public std::exception {const char *what(void) const throw() {return "there's only one element or there's no element in your container";}};
class Span::InvalidArg : public std::exception   {const char *what() const throw() {return "invalid argument";}};

Span::Span(void){}
Span::~Span(void){}
Span::Span(const Span &obj)
{
    values.resize(obj.N);
    N = obj.N;
    for (unsigned int i = 0; i < obj.N; i++)
        values[i] = obj.values[i];
}

Span &Span::operator=(const Span &obj)
{
    if (this == &obj)
        return *this;
    N = obj.N;
    for (unsigned int i = 0; i < obj.N; i++)
        values[i] = obj.values[i];
    return *this;
}

Span::Span(unsigned int N)
{
    this->N = 0;
    if (N == 0)
        throw Span::InvalidArg();
    this->N = N;
}

void Span::addNumber(int num)
{
    if (values.size() == N)
        throw Span::CantAddMore();
    values.push_back(num);
}


unsigned int Span::shortestSpan(void)
{
    if (values.size() <= 1)
        throw Span::CantFindSpan();

    std::sort(values.begin(), values.end());
    unsigned int res = values[1] - values[0];

    for (unsigned int i = values.size() - 1; (i - 1) > 0; i--)
    {
        if ((values[i] - values[i - 1]) < (int)res)
            res = values[i] - values[i - 1];
    }
    return res;
}

unsigned int Span::longestSpan(void)
{
    if (values.size() <= 1)
        throw Span::CantFindSpan();

    std::sort(values.begin(), values.end());
    unsigned int res =  values[values.size() - 1] - values[0];
    return res;
}

// const char * Span::CantAddMore::what(void) const throw() {return "your reach the limit you can't add more numbers";};


