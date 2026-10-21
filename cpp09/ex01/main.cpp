/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml-hote <ml-hote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 00:28:55 by ml-hote           #+#    #+#             */
/*   Updated: 2026/10/22 00:30:38 by ml-hote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	RPN
	Your program must take an inverted Polish mathematical expression as an argument.
	Done using std::stack, calculating the result using mostly the top 2 elements on
	the go when given an expression.
*/

#include "RPN.hpp"

int	main(int ac, char **av)
{
	RPN myRPN;
	if (ac > 2)
	{
		std::cout << "Must use program this way : ./RPN `expression`" << std::endl;
		return (-1);
	}
	myRPN.calculate(av[1]);
	if (!myRPN.get_error())
		std::cout << myRPN.get_result() << std::endl;
	return (0);
}