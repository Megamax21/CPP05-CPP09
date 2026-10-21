/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml-hote <ml-hote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 00:28:39 by ml-hote           #+#    #+#             */
/*   Updated: 2026/10/22 00:28:40 by ml-hote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	main(int ac, char **av)
{
	BitcoinExchange *test = new BitcoinExchange();
	//std::cout << "Hello !" << std::endl;
	if (ac != 2)
	{
		std::cout << "Use of program must be : ./btc `input_file`" <<std::endl;
		return (-1);
	}
	// std::cout << test->checkForValue(20190515) << std::endl;
	test->convertInput(av[1]);
	return (0);
}