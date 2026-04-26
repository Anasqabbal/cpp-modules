#include "BitcoinExchange.hpp"



// CCF
// create and initialise the database
void BitcoinExchange::OpenAndSetDataBase(void)
{
	std::ifstream DataFile("data.csv");
	std::string date = "";
	std::string value= "";

	if (!DataFile.is_open())
	{
		std::cout << "can't open or find data file (data.csv)"  << std::endl;
		exit (1);
	}
	{
		std::string line = "";
		if (!getline(DataFile, line)) // to skip the first line
		{
			std::cout << "empty file" << std::endl;
			exit (1);
		}
		while(getline(DataFile, line))
		{
			size_t ind = line.find(",");
			date = line.substr(0, ind);
			value = line.substr(ind + 1);
			db[date] = value;
		}
	}
}

BitcoinExchange::BitcoinExchange()
{
	OpenAndSetDataBase();
}

BitcoinExchange::~BitcoinExchange(){};

BitcoinExchange::BitcoinExchange(const BitcoinExchange &obj)
{
    db = obj.db;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &obj)
{
    if (&obj != this)
        db = obj.db;
    return *this;
}

int		BitcoinExchange::ErrorInvalidFormat(std::string &val)
{
	std::cout << "Error: invalid date format: " << val << std::endl;
	return -1;
}

bool		BitcoinExchange::CheckLeapYear(const int &year)
{
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		return 1;
	return 0;
}

int BitcoinExchange::ItIsValidDateFormat(std::string date)
{
	std::string OriginValue = date;
	{
		std::string YearStr;
		std::string MonthStr;
		std::string DayStr;
		char		CountHyphen = 0;

		for (size_t i = 0; (date[i]); i++)
		{
			if (date[i] == '-')
			{
				CountHyphen++;
				switch (CountHyphen)
				{
					case 1:
						YearStr = date.substr(0, i);
						date = date.substr(i + 1);
						i = 0;
						break;
					case 2:
						MonthStr = date.substr(0, i);
						date = date.substr(i + 1);
						i = 0;
						break;
					default:
						return ErrorInvalidFormat(OriginValue);
				}
			}
		}
		DayStr = date;
		if (!CountHyphen || CountHyphen != 2)
			return  ErrorInvalidFormat(OriginValue);
		if (YearStr.size() != 4 || MonthStr.size() != 2  || (DayStr.size() != 2))
			return  ErrorInvalidFormat(OriginValue);
		{
			if ((DayStr.find_first_not_of("0123456789") != std::string::npos) || (MonthStr.find_first_not_of("0123456789") != std::string::npos) || (YearStr.find_first_not_of("0123456789") != std::string::npos))
				return  ErrorInvalidFormat(OriginValue);
			int Year  = std::strtol(YearStr.c_str(), NULL, 10);	
			int Month = std::strtol(MonthStr.c_str(), NULL, 10);	
			int Day  = std::strtol(DayStr.c_str(), NULL, 10);

			if (Year < 1 || Month < 1 || Day < 1 || Month > 12 || Day > 31)
				return std::cout << "Error: bad input: " << OriginValue << std::endl, -1;
			if ((Month == 4 || Month == 6 || Month == 9 || Month == 11) && Day > 30 || Month == 2 && Day > 29)
				return std::cout << "Error: bad input: " << OriginValue << std::endl, -1;
			if (Month == 02  && Day == 29 && !CheckLeapYear(Year))
				return std::cout << "Error:  "<< YearStr << " is not a leap year " << OriginValue << std::endl, -1;
		}
	}
    return 0;
}

int BitcoinExchange::ItIsValidValueFormat(std::string value)
{
	char *end = NULL;
	double val = std::strtod(value.c_str(), &end);
    size_t i = 0;
    int fp = 0;

	if (end && !(*end))
	{
		if (val < 0)
			return std::cout << "Error: not a positive number" << std::endl, -1;
		else if (val > 1000)
			return std::cout << "Error: too large number" << std::endl, -1;
	}
	else
		return  std::cout << "Error: bad input: " << value << std::endl, -1;
    return 0;
}

int BitcoinExchange::ItIsValidLineFormat(const size_t & cl)
{
    if (cl == 0)
        return std::cout << "Error: your file is empty" << std::endl, -1;
    else if (cl == std::string::npos)
        return  std::cout << "Error : Invalid line Format" << std::endl, -1;
    return 0;
}

// another memberfunctions
std::string BitcoinExchange::cut(std::string obj)
{
	size_t first(0);
	size_t last(0);

	first = obj.find_first_not_of(" \t\n\v\f\r");
	last = obj.find_last_not_of(" \t\n\v\f\r");
	if (first == std::string::npos)
		first = 0;
	if (last == std::string::npos)
	{
		if (first)
			last = obj.size() - first;
	}
	return obj.substr(0, last + 1).substr(first);
}

double BitcoinExchange::GenerateTheVal(const std::string &val1, const std::string &val2)
{
	return strtod(val1.c_str(), NULL) * strtod(val2.c_str(), NULL);
}

static std::string	NumToStr(const long &val)
{
	std::stringstream ss;
	if (val < 10)
		ss << "0";
	ss << val;
	return ss.str();
}

void	BitcoinExchange::DecrementTheDate(std::string &date)
{
	long year;
	long month;
	long day;

	year 	= strtol(date.substr(0, date.find("-")).c_str(), NULL, 10);
	month 	= strtol(date.substr(5 , date.find("-", 5)).c_str(), NULL, 10);
	day 	= strtol(date.substr(8).c_str(), NULL, 10);

	{
		long first = std::strtol(((db.begin())->first).substr(0, 4).c_str(), NULL, 10);
		long last = std::strtol(((--db.end())->first).substr(0, 4).c_str(), NULL, 10);

		if (year < first)
		{
			date = db.begin()->first; 
			return ;
		}
		else if ((year > last))
		{
			 date = (--db.end())->first; 
			 return;
		}
	}


	if (day - 1 < 1)
	{
		if (month - 1 < 1)
		{
			month = 12;
			year -= 1;
		}
		else
			month -= 1;
		if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8)
			day = 31;
		else if (month == 2 && CheckLeapYear(year))
			day = 29;
		else if (month == 2)
			day = 28;
		else
			day = 30;
	}
	else
		day -= 1;
	date = NumToStr(year) + "-" + NumToStr(month) + "-" + NumToStr(day);
}

void	BitcoinExchange::FindAndPrintTheRes(const std::string &date, const std::string &value)
{
	std::map<std::string, std::string>::iterator it = db.find(date);
	if (it != db.end())
	{
		std::cout << date << " => " << value << " = " << GenerateTheVal(value, it->second) << std::endl;
	}
	else
	{
		it = db.end();
		std::string UpDatedDate = date;
		while (it == db.end())
		{
			DecrementTheDate(UpDatedDate);
			it = db.find(UpDatedDate);
		}
		std::cout << date << " => " << value << " = " << GenerateTheVal(value, it->second) << std::endl;
	}
}

BitcoinExchange::BitcoinExchange(const std::string &FileName)
{
	OpenAndSetDataBase();

    std::ifstream Input(FileName.c_str());

    if (!Input.is_open())
    {
        std::cout << "Error : can't open the file" << std::endl;
        return ;
    }
    
    std::cout << "Valid file start working" << std::endl;
    {
        std::string line;
        std::string date;
        std::string value;
        size_t ind = 0;
		
        while (getline(Input, line))
        {
            if (line.empty())
			{
                std::cout << "Error: empty line" << std::endl;
				continue;
			}
            ind = line.find("|");
            if (ind != std::string::npos)
            {
                date = cut(line.substr(0, ind));
                value = cut(line.substr(ind + 1));
				if (date == "date" && value == "value")
					continue ;
                if (!date.empty() && !value.empty() && !ItIsValidDateFormat(date) && !ItIsValidValueFormat(value))
					FindAndPrintTheRes(date, value);
				else if (date.empty() || value.empty())
					std::cout << "Error: bad input: " << line << std::endl;
            }
            else
            {
				if (( date == "date" && value == "value"))
					continue;
                if (!ItIsValidDateFormat(line.substr(0)))
					std::cout << "Error: bad input: " << line << std::endl;
				else
					std::cout << "Error: Invalid line format" << std::endl;
            }
        }
    }
    Input.close();
}

// Inecessary member functions
void BitcoinExchange::PrintAllDb(void)
{
	std::map<std::string, std::string>::iterator it;
	for (it = db.begin(); it != db.end(); it++)
	{
		std::cout << (*it).first << ",";
		std::cout  << (*it).second << std::endl;
	}
}