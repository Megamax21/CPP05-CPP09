/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_00.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml-hote <ml-hote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 20:36:21 by ml-hote           #+#    #+#             */
/*   Updated: 2026/05/10 23:54:47 by ml-hote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/utils.hpp"

void ft_print_char(std::string input)
{
	std::cout << "char : ";
	
	if (input.length() == 1 && isprint(input[0]) && !isdigit(input[0]))
	{
		// IF THE INPUT IS A SINGLE CHAR
		std::cout << input[0] << std::endl; 
	}
	else 
	{	
		// IF THE INPUT IS A NUMERIC VALUE
		int i_input = atoi(input.c_str());
		if (isprint(i_input))
			std::cout << static_cast<char>(i_input) << std::endl;
		else if (i_input >= 0 && i_input <= 255)
			std::cout << "Non displayable" << std::endl;
		else
			std::cout << "Impossible" << std::endl;
	}
}