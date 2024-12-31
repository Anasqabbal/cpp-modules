#include "Fixed.hpp"
#include <sstream>
#include <string>
const int Fixed::nfb = 8;

Fixed::Fixed(const Fixed &fpv)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fpv;
}

Fixed::Fixed(void)
{
	std::cout << "Defaul constructor called" << std::endl;
	fpv = 0;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

void Fixed::operator=(const Fixed &ob1)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (&ob1.fpv != &this->fpv)
		fpv = ob1.getRawBits();
}

Fixed::Fixed(const int number)
{
	std::cout << "Int constructor called" << std::endl;
	fpv = number << nfb;
}

static void reverse_string(std::string &str)
{
	std::string NewStr;
	int i = 0;

	for (i = (str.size()) - 1; i >= 0; i--)
		NewStr += str[i];
	NewStr += '\0';
	str.swap(NewStr);
}

static void IntToBinary(int nb, std::string &Intnb)
{
	int i;
	int sign = 1;

	sign *= nb < 0 ? -1 : 1;
	nb *= nb < 0 ? -1 : 1;
	Intnb.erase();
	while(nb && Intnb.size() != 22)
	{
		Intnb += nb % 2  == 1 ? '1' : '0';
		nb /= 2;
	}
	for (i = Intnb.size(); (i < 23); i++)
		Intnb += '0';
	for (int i = 0; Intnb[i]; i++)
		nb += Intnb[i] == '1' ? pow(2, i) : 0;
	Intnb += sign == -1 ? '1' : '0';
}

static void DecToBinary(int nb, std::string &Frcpart, int nfb)
{
	float fl = nb * pow(10, (int)Frcpart.size() * -1);
	float v = 0.0f;
	Frcpart.clear();
	for (int i = nfb; (fl != 0 && i); i--)
	{
		fl *= 2.0f;
		if (fl >= 1)
		{
			Frcpart += '1';
			fl -= 1.0f;
		}
		else
			Frcpart += '0';
	}
}

static float GetValueAsFloat(std::string bin, int bits, int nfb)
{
	float value;
	int i;

	value = 0;
	for(i = 0; i < nfb; i++)
		value += bin[i] == '1' ? pow(2, ((i + 1) * -1)) : 0;
	for (int j = 0; j < (bits - nfb - 1); j++)
		value += bin[i++] == '1' ? pow(2, j) : 0;
	if (bin[31] == '1')
		return (value * -1);
	return (value);
}

int	StoreValueAsInt(std::string bin, int bits)
{
	int value;

	value = 0;
	for (int j = 0; j < (bits - 1); j++)
		value += bin[j] == '1' ? pow(2, j) : 0;
	if (bin[31] == '1')
		return (value * -1);
	return (value);
}

static void to_binary(int tm, std::string &bin)
{
	int sign;
	int i;

	sign = tm < 0 ? -1 : 1;
	bin.clear();
	for (i = 0; (i < 31); i++)
	{
		bin += tm % 2 == 1 ? '1' : '0';
		tm /= 2;
	}
	bin += sign == -1 ? '1' : '0';
}

Fixed::Fixed(const float number)
{
	int i = 0;
	int find = 0;
	float an = 0;
	std::ostringstream str;
	std::string Intpart;
	std::string Frcpart;

	std::cout << "Float constructor called" << std::endl;
	str << number;
	Frcpart = str.str();
	Intpart = str.str();
	Intpart = Intpart.erase(Intpart.find('.', 0));
	Frcpart = Frcpart.substr(Frcpart.find('.', 0) + 1);
	DecToBinary(std::atoi(Frcpart.c_str()), Frcpart, nfb);
	IntToBinary(std::atoi(Intpart.c_str()), Intpart);
	fpv = StoreValueAsInt(Frcpart + Intpart, 32);
}

int	Fixed::toInt(void) const
{
	return (fpv >> nfb);
}

float Fixed::toFloat(void) const
{
	float	val;
	std::string bin;
	
	to_binary(fpv, bin);
	val = GetValueAsFloat(bin, 32, nfb);
    return (val);
}

std::ostream &operator<< (std::ostream &output, const Fixed &obj)
{
	output << obj.toFloat();
	return (output);
}


int Fixed::getRawBits( void ) const
{
	return (fpv);
}

void Fixed::setRawBits( int const raw )
{
	fpv = raw;
}
