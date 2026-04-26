#include <iostream>
#include <fstream>
#include "Utils.hpp"

int main(int ac, char **av)
{
	if (ac != 4)
		std::cout << "invalid argument\n";
	else
	{
		std::string		line;
		std::ifstream	inFile(av[1], std::ios::in);
		std::ofstream	outFile;
		std::string		newone;
		std::string		name = av[1];

	
		if (!inFile.is_open())
			return (std::cout << "error: can't open file\n", 1);
		newone = name + ".replace";
		outFile.open(newone.c_str(), std::ios::out);
		if (!outFile.is_open())
			return (inFile.close(), 1);
		newone.clear();
		while(std::getline(inFile, line, '\0')) 
		{
			while(find_and_replace(line, av[2], av[3], newone) != -1);
			outFile << newone;
		}
		inFile.close();
		outFile.close();
	}
}