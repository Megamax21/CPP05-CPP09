/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml-hote <ml-hote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 23:52:47 by ml-hote           #+#    #+#             */
/*   Updated: 2026/06/10 01:37:25 by ml-hote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int i) : N(i)
{
	std::cout << "Span constructor called" << std::endl;
}

Span::~Span()
{
	std::cout << "Span destructor called" << std::endl;
}

void Span::addNumber(int i)
{
	array.push_back(i);
	sort(array.begin(), array.end());
	for (int j = 0 ; j < (int)array.size() ; j++)
	{
		std::cout << array[j] << " ";
	}
	std::cout << std::endl;
}