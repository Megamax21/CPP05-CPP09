/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_00.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml-hote <ml-hote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 20:36:21 by ml-hote           #+#    #+#             */
/*   Updated: 2026/05/14 13:03:53 by ml-hote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/utils.hpp"

int	parser(std::string input)
{
	if (input.empty())
		return (-1);
	
	// Single character (non-digit)
	if (input.length() == 1)
	{
		if (isdigit(input[0]))
			return ((input[0] - '0'));
		else
			return ((int)input[0]);
	}
	
	// Check for special float values
	if (input == "nanf" || input == "nan" || input == "+inff" || input == "-inff" 
		|| input == "+inf" || input == "-inf")
		return (1);
	
	// Remove 'f' or 'd' suffix if present
	std::string to_validate = input;
	char suffix = '\0';
	if (!to_validate.empty() && (to_validate[to_validate.length() - 1] == 'f' 
		|| to_validate[to_validate.length() - 1] == 'd'))
	{
		suffix = to_validate[to_validate.length() - 1];
		to_validate = to_validate.substr(0, to_validate.length() - 1);
	}
	
	if (to_validate.empty())
		return (-1);
	
	bool has_point = false;
	size_t i = 0;
	
	// Allow optional sign at start
	if (to_validate[i] == '+' || to_validate[i] == '-')
		i++;
	
	if (i >= to_validate.length())
		return (-1);
	
	// Check remaining characters
	bool has_digit = false;
	while (i < to_validate.length())
	{
		if (isdigit(to_validate[i]))
		{
			has_digit = true;
			i++;
		}
		else if (to_validate[i] == '.' && !has_point)
		{
			has_point = true;
			i++;
		}
		else
		{
			return (-1);  // Invalid character
		}
	}
	
	// Must have at least one digit
	if (!has_digit)
		return (-1);
	
	return (1);
}

float ft_print_double(std::string input)
{
	double f = std::atof(input.c_str());

	if (f != f)
		std::cout << "double : nanf" << std::endl;
	else if (std::isinf(f))
	{
		std::cout << "double : ";
		if (f > 0)
			std::cout << "+inff";
		else
			std::cout << "-inff";
		std::cout << std::endl;
		
	}
	else if (f == std::floor(f) && std::isfinite(f))
		std::cout << "double : " << f << ".0" << std::endl;
	else
		std::cout << "double : " << std::fixed << std::setprecision(15) << f << std::endl;
	
	if (f <= std::numeric_limits<float>::max() && f >= std::numeric_limits<float>::min())
		return ((float)f);
	else
		return (-1);
}

/* Returns -1 if float is not an int 
	otherwise, returns the int value */
int ft_print_float(std::string input)
{
	float f = (float)std::atof(input.c_str());

	if (f != f)
		std::cout << "float : nanf" << std::endl;
	else if (std::isinf(f))
	{
		std::cout << "float : ";
		if (f > 0)
			std::cout << "+inff";
		else
			std::cout << "-inff";
		std::cout << std::endl;
		
	}
	else if (f == std::floor(f) && std::isfinite(f))
		std::cout << "float : " << f << ".0f" << std::endl;
	else
		std::cout << "float : " << std::fixed << std::setprecision(7) << f << "f" << std::endl;
	
	if (f <= std::numeric_limits<int>::max() && f >= std::numeric_limits<int>::min())
		return ((int)f);
	else
		return (-1);
}

int	ft_print_int(std::string input)
{
	std::cout << "int : ";
	int i = std::atoi(input.c_str());
	if (i < std::numeric_limits<int>::min()
		|| i > std::numeric_limits<int>::max())
	{
		std::cout << "impossible" << std::endl;
		return (-1);
	}
	else
	{
		std::cout << i << std::endl;
		return(i);
	}
}

void ft_print_char(int input)
{
	if (input == -1 || input > 255 || input < 0)
	{
		std::cout << "char : impossible" << std::endl;
	}
	else
	{
		if (isprint(input))
			std::cout << "char : " << (char)input << std::endl;
		else
			std::cout << "char : Non displayable" << std::endl;
	}
}