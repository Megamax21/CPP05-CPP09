/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml-hote <ml-hote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 11:50:54 by ml-hote           #+#    #+#             */
/*   Updated: 2026/11/14 06:24:51 by ml-hote          ###   ########.fr       */
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

void	print_v_of_v_with_order(std::vector<std::vector<int> > v_of_v, int order)
{
	std::cout << "[";
	int a = 0, b = 0;
	bool letterswitch = false; // false = a true = b
	int i = 0;
	int j = 0;
	int pair = 0;
	while (i < (int)v_of_v.size())
	{
		if (letterswitch)
		{
			std::cout << " b" << b << " ";
			b++;
		}
		else
		{
			std::cout << " a" << a << " ";
			a++;
		}
		letterswitch = !letterswitch;
		std::cout << "[";
		pair++;
		while (j < order && i < (int)v_of_v.size())
		{
			if (j > 0)
				std::cout << ", ";

			std::cout << v_of_v[i].back();
			i++;
			j++;
		}
		j = 0;
		i++;
		std::cout << "]";
		if (pair == 2)
		{
			pair = 0;
			if ((int)v_of_v.size() - i < order)
				break;
		}
	}
	std::cout << "]" << std::endl;
	// if ((int)v_of_v.size() - i >= order)
	// {
	// 	if (letterswitch)
	// 	{
	// 		std::cout << " b" << b << " ";
	// 		b++;
	// 	}
	// 	else
	// 	{
	// 		std::cout << " a" << a << " ";
	// 		a++;
	// 	}
	// 	while (j < order)
	// 	{
	// 		std::cout << v_of_v[i].back();
	// 		if (j < order - 1)
	// 			std::cout << ", ";
	// 		j++;
	// 		i++;
	// 	}
	// 	std::cout << "]" << std::endl;
	// }
	if (i < (int)v_of_v.size())
	{
		std::cout << "Incomplete leftovers : [";
		while (i < (int)v_of_v.size())
		{
			std::cout << v_of_v[i].back();
			if (i < (int)v_of_v.size() - 1)
				std::cout << ", ";
			i++;
		}
		std::cout << "]" << std::endl;
	}
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
	std::vector<std::vector<int> > vector_of_vectors = v_to_vv(v_sequence);
	fordJohnsonVector(vector_of_vectors);
}

int	PmergeMe::fordJohnsonVector(std::vector<std::vector<int> >& v_of_v)
{
	static int order = 1; // Size of the vectors
	std::vector<std::vector<int> > new_vv;
	// Sorting the pairs :
	if (order == 1)
	{
		int sorting = 1;
		while (sorting <= (int)v_of_v.size()-1)
		{
			if (v_of_v[sorting].back() < v_of_v[sorting - 1].back())
				std::swap(v_of_v[sorting], v_of_v[sorting - 1]);
			if (sorting + 2 > (int)v_of_v.size() - 1)
				break;
			sorting+=2;
		}
		new_vv = v_of_v;
	}
	else
	{
		int	i = 0;
		int	v_size = 0;
		int pairing = 0;
		int	i_vector = 0;
		new_vv.push_back(std::vector<int>());
		while (i < (int)(vv_to_v(v_of_v).size()))
		{
			// std::cout << "i = " << i << " " << vv_to_v(v_of_v)[i] << std::endl;
			new_vv[i_vector].push_back(vv_to_v(v_of_v)[i]);
			i++;
			v_size++;
			if (v_size == order)
			{
				pairing++;
				// Sorting the vectors as we go
				if (pairing == 2)
				{
					if ((int)new_vv[i_vector].size() == order)
					{
						if (new_vv[i_vector].back() < new_vv[i_vector - 1].back())
							std::swap(new_vv[i_vector], new_vv[i_vector - 1]);
					}
					pairing = 0;
				}
				// Create a new vector if not at the end
				if (i < (int)(vv_to_v(v_of_v).size()))
					new_vv.push_back(std::vector<int>());
				v_size = 0;
				i_vector++;
			}
		}
	}
	std::cout << "Order : " << order << std::endl;
	order *= 2;
	print_v_of_v(new_vv);
	// Reset of the vector but with the changes
	//std::cout << "test of 2 functions" << std::endl;
	v_of_v = v_to_vv(vv_to_v(new_vv));
	//print_v_of_v(v_of_v);
	if ((int)vv_to_v(v_of_v).size() / 2 >= order)
		fordJohnsonVector(v_of_v);

	// !!!! START OF THE BACKTRACKING

	if ((int)vv_to_v(v_of_v).size() / 2 < order)
		std::cout << "\n\nBacktrack is starting here !!\n" << std::endl;
	order /= 2;
	std::cout << "Order : " << order << std::endl;
	print_v_of_v_with_order(v_of_v, order);
	return (0);
}