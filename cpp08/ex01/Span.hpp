/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml-hote <ml-hote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 13:37:03 by ml-hote           #+#    #+#             */
/*   Updated: 2026/06/10 11:00:29 by ml-hote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cstdlib>
#include <ctime>

class Span
{
	private :
		unsigned int	N;
		std::vector<int> array;
	public :
		Span();
		Span(unsigned int n);
		~Span();
		void	addNumber(int i);
		void	print();
		int		shortestSpan();
		int		longestSpan();
};

#endif