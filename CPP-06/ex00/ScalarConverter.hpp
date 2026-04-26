#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <cfloat>
#include <cmath>
#include <cstdlib>
#include <climits>
#include <cerrno>
#include <iomanip>

class ScalarConverter{
    private:
    ScalarConverter(void);
    ScalarConverter (const ScalarConverter &obj);
    public:
    ScalarConverter &operator=(const ScalarConverter &obj);
    
    static void convert(std::string str);
    ~ScalarConverter(void);
    };
#endif
