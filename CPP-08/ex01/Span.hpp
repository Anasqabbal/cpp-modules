#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

class Span
{
    private:
    std::vector<int>    values;
    unsigned int        N;

    public:
    Span(void);
    Span(const Span &obj);
    ~Span();
    Span &operator=(const Span &obj);

    class CantAddMore : public std::exception
    {
    public:
        virtual const char* what() const throw()
        {
            return "your reach the limit you can't add more numbers";
        }
    };

    class CantFindSpan;
    class InvalidArg ;

    Span(unsigned int N);
    void addNumber(int num);
    unsigned int shortestSpan(void);
    unsigned int longestSpan(void);

    template<typename InputIt>
    void addNumber(InputIt begin, InputIt end)
    {
        if ((end - begin) > N)
            throw Span::CantAddMore();
        values.insert(values.end(), begin, end);
    }
};

#endif
