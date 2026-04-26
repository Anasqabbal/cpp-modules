#include "ScalarConverter.hpp"


ScalarConverter::ScalarConverter(void)
{

}
ScalarConverter::~ScalarConverter()
{

}
ScalarConverter::ScalarConverter(const ScalarConverter &obj)
{
    (void) obj;
}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &obj)
{
    (void) obj;
    return *this;
}

static void PrintChar(const long val)
{
    std::cout << "char: ";
    if ((val >= 0 && val <= 31) || val == 127)
        std::cout << "Non Displayable";
    else if (val > 31 && val < 127)
        std::cout << "\'" << static_cast<char> (val) << "\'";
    else
        std::cout << "impossible";
    std::cout << std::endl;
}

static void PrintInt(const long long val)
{
    std::cout << "int : ";
    if (val <= INT_MAX && val >= INT_MIN)
        std::cout <<  static_cast<int> (val) << std::endl;
    else
		std::cout << "impossible" << std::endl;
}

static void PrintFloat(const float val, const int &ind)
{
	std::cout << "float: ";
		std::cout << std::fixed << std::setprecision(1) << static_cast<float>  (val);
	if (ind && val <= FLT_MAX && val >= FLT_MIN)
		std::cout << ".0";
	std::cout  << "f" << std::endl;
}

static void PrintDouble(const double val, const int &ind)
{
	std::cout << "Double: ";
	std::cout  << static_cast<double> (val);
	if (ind && val <= DBL_MAX && val >= DBL_MIN)
		std::cout << ".0";
	std::cout  << std::endl;
}

void ScalarConverter::convert(std::string str)
{
	char	*end = NULL;
	double	val = std::strtod(str.c_str(), &end);
	float	val1 = std::strtof(str.c_str(), &end);
	size_t	ind = str.find(".") ;
	int		InvalidExpression = 0;
	int		ind1 = 0;
	std::string end1 = end;


	std::cout << "--->>>";
	std::cout << end;
	std::cout << "<<<<-----" << std::endl;
	if ((val == 0 && end1.size() == 1) || (val == 0 && !end1.size())) 
		val = *end;
	else if (((ind != std::string::npos)) && val)
	{
		if (std::isdigit(str[ind + 1]))
		{
			if (str[str.size() - 1] == 'f')
			{
				if (str.find_first_not_of("0123456789", ind + 1, end1.size() - 2) != std::string::npos)
					InvalidExpression = 1;
			}
			else if (*end)
				InvalidExpression = 1;
		}
		else
			InvalidExpression = 1;
	}
	else if ((val == 0 && end1.size() > 1))
		InvalidExpression = 1;
	else if (val && *end && ind == std::string::npos)
	{
		if (end1 == "f" && end1.size() == 1)
			InvalidExpression = 0;
		else
			InvalidExpression = 1;
	}
	else if (val && !(*end))
		ind1 = 0;

	if (InvalidExpression)
	{
		std::cout << "Invalid Expression" << std::endl;
		return ;
	}

	std::cout << str << std::endl;
	std::cout << val << std::endl;
	std::cout << val1 << std::endl;
	PrintChar(val);
	PrintInt(val);
	PrintFloat(val, ind1);
	PrintDouble(val, ind1);
}