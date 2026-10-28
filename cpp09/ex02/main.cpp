/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml-hote <ml-hote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 11:51:00 by ml-hote           #+#    #+#             */
/*   Updated: 2026/10/28 15:53:18 by ml-hote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main(int ac, char **av)
{
	if (ac == 1)
	{
		std::cout << "input must be : > ./PmergeMe [array of positive integers]" << std::endl;
		return (-1);
	}
	std::cout << av[1] << std::endl;
	std::cout << "Let's sort some numbers" << std::endl;
	PmergeMe(ac, av);
	
	return (0);
}