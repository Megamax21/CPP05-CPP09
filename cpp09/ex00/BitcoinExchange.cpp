#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	// Data map filling 
	std::ifstream btc_database("data.csv");
	std::string line;
	// int i = 0;
	std::getline(btc_database, line);
	std::getline(btc_database, line);
	datamap.insert(std::map<int, float>::value_type(convertLineToDate(line), convertLineToValue(line)));
	while (std::getline(btc_database, line))
	{
		if (datamap.rbegin()->second != convertLineToValue(line))
			datamap.insert(std::map<int, float>::value_type(convertLineToDate(line), convertLineToValue(line)));
	}
	//std::cout << "Constructor called" << std::endl;
}

BitcoinExchange::~BitcoinExchange()
{
	//std::cout << "Destructor called" << std::endl;
}

int	BitcoinExchange::convertLineToDate(std::string line)
{
	std::string number_str = "";
	for (int i = 0; i < 11 ; i++)
	{
		if (std::isdigit(line[i]))
			number_str.push_back(line.c_str()[i]);
	}
	// std::cout << "test :" << number_str << std::endl;
	return (atoi(number_str.c_str()));
}

float BitcoinExchange::convertLineToValue(std::string line)
{
	std::string number_str = "";
	int i = 11;
	while (line[i] != '\0')
	{
		//std::cout << "line[i] = " << line[i] << std::endl;
		if (isdigit(line[i]) || line[i] == '.')
			number_str.push_back(line.c_str()[i]);
		i++;
	}
	//std::cout << "test cltv :" << number_str << std::endl;
	return (atof(number_str.c_str()));
}

float	BitcoinExchange::checkForValue(int date)
{
	std::ifstream	btc_database("data.csv");
	std::string		line;
	for (std::map<int, float>::iterator it = datamap.begin(); it != datamap.end(); ++it)
	{
		if (it->first >= date)
			return (it->second);
	}
	return (-1);
}

int	BitcoinExchange::parseLine(std::string line)
{
	std::string str_value = "";
	// Date checking
	for (int i = 0 ; i < 4 ; i++) // Year Checking
	{
		if (!isdigit(line[i]))
			return (-1);
		str_value.push_back(line[i]);
	}
	// std::cout << str_value;
	if (atoi(str_value.c_str()) > 2022)
		return (-1);
	str_value.clear();

	if (line[4] != '-' || !isdigit(line[5]) || !isdigit(line[6]) || line[7] != '-'
			|| !isdigit(line[8]) || !isdigit(line[9]) || line[10] != ' ' || line [11] != '|' || line [12] != ' ') // Dirty syntax checker 
		return (-1);
	// Month Checking
	str_value.push_back(line[5]);
	str_value.push_back(line[6]);
	// std::cout << str_value;
	if (atoi(str_value.c_str()) < 1 || atoi(str_value.c_str()) > 12)
		return (-1);
	str_value.clear();

	// Day Checking
	str_value.push_back(line[8]);
	str_value.push_back(line[9]);
	// std::cout << str_value ;
	if (atoi(str_value.c_str()) < 1 || atoi(str_value.c_str()) > 31)
		return (-1);
	
	str_value.clear();
	int j = 13;
	int dot = 0;
	if (line[j] == '-')
		return (-2); // Case if number is neg
	while (line[j] != '\0')
	{
		if (line[j] == '.' && dot == 0)
		{
			if (j == 13)
				return (-3); // Case if number starts with a '.'
			dot = 1;
			str_value.push_back(line[j]);
		}
		else
		{
			if (!isdigit(line[j]))
				return (-4); // Case if number is not a number
			str_value.push_back(line[j]);
		}
		j++;
	}
	if (atof(str_value.c_str()) > 1000)
		return(-5);
	return (0);
}

void	BitcoinExchange::lineErrorPrinting(int i)
{
	if (i < 0)
		std::cout << "Error : ";
	switch (i)
	{
	case -1:
		std::cout << "Bad input => ";
		break;

	case -2:
		std::cout << "Not a positive number" << std::endl;
		break;

	case -3:
		std::cout << "Number isn't a number !" << std::endl;
		break;

	case -4:
		std::cout << "Number isn't a number !" << std::endl;
		break;

	case -5:
		std::cout << "Too large number" << std::endl;
		break;

	default:
		break;
	}
}

/* When entering this function we assume that the line argument should be parsed and correct ! */
void	BitcoinExchange::rewriteInputLine(std::string line)
{
	std::string newLine;
	for (int i = 0 ; i < 11 ; i++) // Until the '|' char to pickup the date
		newLine.push_back(line[i]);
	newLine.append("=> ");
	int j = 13;
	while (line[j] != '\0')
	{
		newLine.push_back(line[j]);
		j++;
	}
	std::cout << newLine;
}
void	BitcoinExchange::convertInput(std::string file_name)
{
	std::string		line;
	std::string		date_str = "";
	std::ifstream	btc_input(file_name.c_str());
	int 			i = 0;

	if (!btc_input)
	{
		std::cout << "Couldn't read file";
		return ;
	}
	std::getline(btc_input, line);
	if (line.compare("date | value") != 0)
	{
		std::cout << "Input file should start with line 'date | value'";
		return;
	}
	while (std::getline(btc_input, line))
	{
		while (line[i] != '|' && line[i])
		{
			date_str.push_back(line[i]);
			i++;
		}
		if (parseLine(line) != 0)
		{
			lineErrorPrinting(parseLine(line));
			if (parseLine(line) == -1)
				std::cout << date_str << std::endl;
		}
		else
		{
			rewriteInputLine(line);
			std::cout << " = " << convertLineToValue(line) * checkForValue(convertLineToDate(line)) << std::endl;
		}

		// Reset the date pickup system line by line
		date_str.clear();
		i = 0;
	}
}