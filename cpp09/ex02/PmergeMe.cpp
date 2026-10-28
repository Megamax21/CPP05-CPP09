/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml-hote <ml-hote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 11:50:54 by ml-hote           #+#    #+#             */
/*   Updated: 2026/10/28 16:22:31 by ml-hote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

bool	ft_is_number(char *number)
{
	int	i = 0;
	if (number[i] == '-')
		i++;
	if (!number)
		return (false);
	while (number[i])
	{
		if (!isdigit(number[i]))
			return (false);
		i++;
	}
	return (true);
}

PmergeMe::PmergeMe()
{
	std::cout << "Created object without args..." << std::endl;
}

PmergeMe::~PmergeMe()
{
	std::cout << "Destructor called" << std::endl;
}

PmergeMe::PmergeMe(int len, char **input)
{
	/* List and Vector fill */
	for (int i = 1; i < len; i++)
	{
		if (!ft_is_number(input[i]))
		{
			std::cout << "Error : Not a number => " << input[i] << std::endl;
			return ;
		}
		if (atoi(input[i]) < 0)
		{
			std::cout << "Error : Negative integer => " << input[i] << std::endl;
			return ;
		}
		v_sequence.push_back(atoi(input[i]));
		l_sequence.push_back(atoi(input[i]));
	}
	
	// TEST
	fordJohnson(v_sequence);
}


#include <vector>
#include <map>
#include <algorithm>

void	PmergeMe::fordJohnson(std::vector<int> &v)
{
	size_t n = v.size();
	if (n < 2)
		return;

	// 1. Pair up: winners go to the recursion, losers are remembered by winner
	std::vector<int>			winners;
	std::multimap<int, int>		losers;	// winner -> loser
	for (size_t i = 0; i + 1 < n; i += 2)
	{
		int big = std::max(v[i], v[i + 1]);
		int small = std::min(v[i], v[i + 1]);
		winners.push_back(big);
		losers.insert(std::make_pair(big, small));
	}
	bool hasStraggler = (n % 2 != 0);

	// 2. Recursively sort the winners
	fordJohnson(winners);

	// 3. Build pend so that pend[i] is the loser paired with winners[i]
	std::vector<int> pend;
	for (size_t i = 0; i < winners.size(); i++)
	{
		std::multimap<int, int>::iterator it = losers.find(winners[i]);
		pend.push_back(it->second);
		losers.erase(it);
	}
	if (hasStraggler)
		pend.push_back(v[n - 1]);	// no partner: its bound will be chain.end()

	// 4. Main chain = sorted winners; pend[0] is smaller than winners[0],
	//    so it goes first with no comparison
	std::vector<int> chain(winners);
	chain.insert(chain.begin(), pend[0]);

	// 5. Insert the rest in Jacobsthal order (1-indexed: 3,2 / 5,4 / 11,10,9,8,7,6 ...)
	size_t m = pend.size();
	size_t a = 1, b = 3;
	while (a < m)
	{
		size_t upper = std::min(b, m);
		for (size_t i = upper; i > a; i--)
		{
			size_t idx = i - 1;	// 0-indexed
			std::vector<int>::iterator bound;
			if (idx < winners.size())
				bound = std::find(chain.begin(), chain.end(), winners[idx]);
			else
				bound = chain.end();	// straggler
			std::vector<int>::iterator pos =
				std::upper_bound(chain.begin(), bound, pend[idx]);
			chain.insert(pos, pend[idx]);
		}
		size_t next = b + 2 * a;
		a = b;
		b = next;
	}
	v = chain;
}