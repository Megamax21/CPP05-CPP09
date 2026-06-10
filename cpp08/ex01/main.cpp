/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml-hote <ml-hote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 00:46:51 by ml-hote           #+#    #+#             */
/*   Updated: 2026/06/10 11:15:55 by ml-hote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
	// --- Generate 10000 unique numbers from 1 to 100000 ---
	std::vector<int> pool(10000);
	for (int i = 0; i < 10000; ++i)
		pool[i] = i + 1;               // fill with 1..100000

	std::srand(std::time(0));
	std::random_shuffle(pool.begin(), pool.end()); // C++98 shuffle

	pool.resize(1000);                // keep first 10000 (all unique)

	// --- Add them to Span ---
	Span sp(1000);
	for (int i = 0; i < 1000; ++i)
		sp.addNumber(pool[i]);

	sp.print();
	std::cout << "Shortest span : " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span : " << sp.longestSpan() << std::endl;
	return 0;
}