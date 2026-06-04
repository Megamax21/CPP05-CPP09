/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml-hote <ml-hote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 13:37:05 by ml-hote           #+#    #+#             */
/*   Updated: 2026/05/30 01:20:10 by ml-hote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

void print_plus(int &a)
{
	std::cout << a+1 << std::endl;
}

int main( void )
{
	std::cout << "before le yo" << std::endl;
	Array<int> a(3);
	std::cout << "yo" << std::endl;
	return 0;
}