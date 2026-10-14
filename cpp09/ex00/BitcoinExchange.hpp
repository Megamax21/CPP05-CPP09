#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>

class BitcoinExchange
{
public:
	BitcoinExchange();
	~BitcoinExchange();
	int		convertLineToDate(std::string line);
	float	convertLineToValue(std::string line);
	float	checkForValue(int date);
	int		parseLine(std::string line);
	void	lineErrorPrinting(int i);
	void	convertInput(std::string file_name);
	void	rewriteInputLine(std::string line);
private:

};

#endif