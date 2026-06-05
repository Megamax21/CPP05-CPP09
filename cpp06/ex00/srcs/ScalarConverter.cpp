/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml-hote <ml-hote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 20:12:30 by ml-hote           #+#    #+#             */
/*   Updated: 2026/06/05 10:21:27 by ml-hote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void ScalarConverter::convert(std::string input)
{
	/* char - int - float - double */
	//ft_print_char(input);
	int parsing = parser(input);
	if (parsing == -1)
	{
		std::cout << "char : impossible" << std::endl;
		std::cout << "int : impossible" << std::endl;
		std::cout << "float : impossible" << std::endl;
		std::cout << "double : impossible" << std::endl;
	}
	else if (parsing == 1)
	{
		// Input is a numeric string: parse the integer value first to print char
		std::string to_convert = input;
		if (!to_convert.empty() && (to_convert[to_convert.length() - 1] == 'f' 
			|| to_convert[to_convert.length() - 1] == 'd'))
		{
			to_convert = to_convert.substr(0, to_convert.length() - 1);
		}
		char *endptr = NULL;
		long i = std::strtol(to_convert.c_str(), &endptr, 10);
		ft_print_char(static_cast<int>(i));
		// Now print the int (reuse existing function which also prints range checks)
		ft_print_int(input);
		ft_print_float(input);
		ft_print_double(input);
	}
	else
	{
		// Single-character input: parser returned the ASCII code (or digit value)
		int i_input = parsing;
		std::stringstream ss;
		ss << i_input;
		input = ss.str();
		ft_print_char(i_input);
		ft_print_int(input);
		ft_print_float(input);
		ft_print_double(input);
	}
}