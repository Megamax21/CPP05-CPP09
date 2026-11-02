/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml-hote <ml-hote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 11:50:54 by ml-hote           #+#    #+#             */
/*   Updated: 2026/11/02 15:25:38 by ml-hote          ###   ########.fr       */
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

int	PmergeMe::fordJohnson(std::vector<int> v)
{
	int	temp = 0;
	if (v.size() > 3)
	{
		fordJohnson(std::vector<int>(v.begin(), v.end() - (v.size() / 2)));
		fordJohnson(std::vector<int>(v.end() - (v.size() / 2), v.end()));
	}
	if (v.size() == 2)
	{
		if (v[0] > v[1])
		{
			temp = v[1];
			v[1] = v[0];
			v[0] = temp;
		}
	}
	for (int i = 0; i < (int)v.size(); i++)
		std::cout << "[" << v[i] << "] ";
	std::cout << std::endl;
	return (0);
}