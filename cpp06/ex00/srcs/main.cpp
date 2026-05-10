/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml-hote <ml-hote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 20:19:43 by ml-hote           #+#    #+#             */
/*   Updated: 2026/05/11 00:23:06 by ml-hote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ScalarConverter.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
		return (1);
	std::cout << "Limits :" << std::endl;
	std::cout << "int :" << std::numeric_limits<int>::min() << " to " << std::numeric_limits<int>::max() << std::endl;
	std::cout << "float :" << std::numeric_limits<float>::min() << " to " << std::numeric_limits<float>::max() << std::endl;
	std::cout << "double :" <<std::numeric_limits<double>::min() << " to " << std::numeric_limits<double>::max() << std::endl;
	ScalarConverter::convert(av[1]);
	return (0);
}