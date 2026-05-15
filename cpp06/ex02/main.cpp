/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml-hote <ml-hote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 02:26:15 by ml-hote           #+#    #+#             */
/*   Updated: 2026/05/15 03:09:35 by ml-hote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

int main(void)
{
	srand(time(0));
	Base* base1;
	for (int i = 0; i < 10; i++)
	{
		std::cout << "=============" << std::endl;
		base1 = generate();
		identify(base1);
		identify(*base1);
	}
	return (0);
}