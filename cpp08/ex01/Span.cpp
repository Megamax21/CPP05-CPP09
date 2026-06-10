/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml-hote <ml-hote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 23:52:47 by ml-hote           #+#    #+#             */
/*   Updated: 2026/06/10 11:12:22 by ml-hote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int i) : N(i)
{
	std::cout << "Span constructor called with arg" << std::endl;
}

Span::~Span()
{
	std::cout << "Span destructor called" << std::endl;
}

Span::Span() : N(0)
{
	std::cout << "Span constructor called" << std::endl;
}

void Span::addNumber(int i)
{
	array.push_back(i);
	sort(array.begin(), array.end());
}

void Span::print()
{
	for (unsigned int i = 0; i < N - 1 ; i++)
		std::cout << array[i] << " ";
	std::cout << array[N-1] << std::endl;
}

int Span::shortestSpan()
{
	int a = 0, b = 0;
	int ss = array[N - 1] - array[0];
	for (unsigned int i = 1 ; i < N ; i++)
	{
		if (array[i] - array[i - 1] < ss)
		{
			a = array[i-1];
			b = array[i];
			ss = array[i] - array[i - 1];
		}
		if (ss == 1)
			return (1);
	}
	std::cout << a << " : " << b << std::endl;
	return (ss);
}

int Span::longestSpan()
{
	return (array[N - 1] - array[0]);
}