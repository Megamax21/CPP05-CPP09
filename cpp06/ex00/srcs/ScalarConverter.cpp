/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml-hote <ml-hote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 20:12:30 by ml-hote           #+#    #+#             */
/*   Updated: 2026/05/14 13:02:06 by ml-hote          ###   ########.fr       */
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
	else if (parsing > -1)
	{
		ft_print_char(parsing);
		ft_print_int(input);
		ft_print_float(input);
		ft_print_double(input);
	}
	else if (parsing > 1)
	{
		int i_input = parsing;
		std::stringstream ss;
		ss << i_input;
		input = ss.str();
		ft_print_char(parsing);
		ft_print_int(input);
		ft_print_float(input);
		ft_print_double(input);
	}
}