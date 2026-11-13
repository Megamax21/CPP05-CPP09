/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml-hote <ml-hote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 11:50:54 by ml-hote           #+#    #+#             */
/*   Updated: 2026/11/13 18:57:40 by ml-hote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void	print_v_of_v(std::vector<std::vector<int> > v_of_v)
{
	std::cout << "[";
	for (int i = 0; i < (int)v_of_v.size(); i++)
	{
		std::cout << "[";
		for (int j = 0; j < (int)(v_of_v[i].size()); j++)
		{
			std::cout<< v_of_v[i][j];
			if (j != (int)v_of_v[i].size() - 1)
				std::cout << ", ";
		}
		std::cout << "]";
		if (i != (int)v_of_v.size() - 1)
			std::cout << ", ";
	}
	std::cout << "]";
	std::cout << std::endl;
}

std::vector<int>	PmergeMe::vv_to_v(std::vector<std::vector<int> > vv)
{
	std::vector<int>	v_output;
	for (int i = 0; i < (int)vv.size(); i++)
	{
		for(int j = 0; j < (int)vv[i].size(); j++)
			v_output.push_back(vv[i][j]);
	}
	return (v_output);
}
std::vector<std::vector<int> >	PmergeMe::v_to_vv(std::vector<int> v)
{
	std::vector<std::vector<int> > vv_output;
	for (int i = 0; i < (int)v.size(); i++)
	{
		vv_output.push_back(std::vector<int>());
		vv_output[i].push_back(v[i]);
	}
	return (vv_output);
}
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
	fordJohnson(v_to_vv(v_sequence));
}

int	PmergeMe::fordJohnson(std::vector<std::vector<int> > v_of_v)
{
	static int order = 1; // Size of the vectors
	// std::vector<std::vector<int> > new_vv;
	// Making pairs :
	// int v_index = 0;
	// int j = 0;
	// if (order == 2) // Sorting pairs before pairing
	// {
	// 	while (j < (int)v.size())
	// 	{
	// 		j++;
	// 		if (j == (int)v.size())
	// 			break;
	// 		if (v[j] < v[j-1])
	// 			std::swap(v[j], v[j - 1]);
	// 		j++;
	// 	}
	// }
	// j = 0;
	// for (int i = 0; i < (int)v.size(); i++) // Vectors are being created
	// {
	// 	new_vv.push_back(std::vector<int>());
	// 	while (j < order)
	// 	{
	// 		new_vv[v_index].push_back(v[i]);
	// 		if (j < order - 1)
	// 			i++;
	// 		j++;
	// 		if (i == (int)v.size())
	// 			break;
	// 	}
	// 	v_index++;
	// 	j = 0;
	// }
	std::cout << "Order : " << order << std::endl;
	order *= 2;
	print_v_of_v(v_of_v);
	if ((int)vv_to_v(v_of_v).size() / 2 > order / 2)
		fordJohnson(v_of_v);

	// order /= 2;
	// std::cout << "Order : " << order << std::endl;
	return (0);
}