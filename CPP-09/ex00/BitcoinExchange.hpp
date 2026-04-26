#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <map>
#include <iterator>
#include <algorithm>
#include <sstream>

class BitcoinExchange
{
	private:
    	std::map<std::string, std::string> db;
		void 		OpenAndSetDataBase(void);
		void 		PrintAllDb(void);
		std::string cut(std::string obj);
		int			ErrorInvalidFormat(std::string &val);
		bool		CheckLeapYear(const int &year);
		void		FindAndPrintTheRes(const std::string &date, const std::string &value);
		double		GenerateTheVal(const std::string &val1, const std::string &val2);
		void		DecrementTheDate(std::string &date);

    public:
    BitcoinExchange();
    ~BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &obj);
    BitcoinExchange &operator=(const BitcoinExchange &obj);
    
    BitcoinExchange(const std::string &FileName);

    int ItIsValidDateFormat( std::string date);
    int ItIsValidValueFormat(std::string value);
    int ItIsValidLineFormat(const size_t &cl);

};


#endif