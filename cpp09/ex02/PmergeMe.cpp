/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml-hote <ml-hote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 11:50:54 by ml-hote           #+#    #+#             */
/*   Updated: 2026/11/14 20:20:02 by ml-hote          ###   ########.fr       */
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
	std::cout << "[" ;
	int a = 0, b = 0;
	bool a_or_b = false; // false == a && true == b
	int	i_vector = 0;

	while (i_vector < (int)v_of_v.size())
	{
		// A or B printing
		if ((int)v_of_v.size() - i_vector >= order)
		{
			if (a_or_b)
			{
				std::cout << "b" << b; 
				b++;
			}
			else
			{
				std::cout << "a" << a;
				a++;
			}
		}
		a_or_b = !a_or_b;
		std::cout << "[";
		for (int i = 0; i < order; i++)
		{
			std::cout << v_of_v[i_vector].back();
			i_vector++;
			if (i_vector == (int)v_of_v.size())
				break;
			else if (i + 1 < order)
				std::cout << ", ";
		}
		std::cout << "]";
		if (i_vector < (int)v_of_v.size())
			std::cout << ", ";
	}

	std::cout << "]" << std::endl;
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

	if (order == 1)
	{
		// Sorting the pairs
		for (int i = 0; i + 1 < (int)v_of_v.size(); i += 2)
		{
			if (v_of_v[i + 1].back() < v_of_v[i].back())
				std::swap(v_of_v[i], v_of_v[i + 1]);
		}
		new_vv = v_of_v;
	}
	else
	{
		const std::vector<int>	flat = vv_to_v(v_of_v); // flattened ONCE
		const int				total = (int)flat.size();
		int						i_vector = 0;

		new_vv.push_back(std::vector<int>());
		for (int i = 0; i < total; i++)
		{
			new_vv[i_vector].push_back(flat[i]);
			if ((int)new_vv[i_vector].size() == order)
			{
				if (i_vector % 2 == 1
					&& new_vv[i_vector].back() < new_vv[i_vector - 1].back())
					std::swap(new_vv[i_vector], new_vv[i_vector - 1]);
				if (i + 1 < total)
				{
					new_vv.push_back(std::vector<int>());
					i_vector++;
				}
			}
		}
	}

	std::cout << "Order : " << order << std::endl;
	order *= 2;
	print_v_of_v(new_vv);

	const std::vector<int>	flat_new = vv_to_v(new_vv);
	v_of_v = v_to_vv(flat_new);

	if ((int)flat_new.size() / 2 >= order)
		fordJohnsonVector(v_of_v);

	// !!!! START OF THE BACKTRACKING
	order /= 2;
	std::cout << "Order : " << order << std::endl;
	print_v_of_v_with_order(v_of_v, order);

	const std::vector<int>	flat = vv_to_v(v_of_v);
	const int				n = (int)flat.size();
	const int				groups = n / order;	// full groups only

	if (groups >= 2)
	{
		const int	pairs = groups / 2;
		const bool	has_odd = (groups % 2 == 1);
		const int	total_b = pairs + (has_odd ? 1 : 0);

		std::vector<std::vector<int> >	chain;		// b1, a1, a2, ... a_pairs
		std::vector<int>				chain_ids;	// id of each chain entry (b_i / a_i -> i)
		std::vector<std::vector<int> >	pend;		// b2, b3, ... (+ odd leftover at the end)

		// Build main chain and pend. Group g = flat[g*order .. (g+1)*order)
		chain.push_back(std::vector<int>(flat.begin(), flat.begin() + order));						// b1
		chain_ids.push_back(1);
		chain.push_back(std::vector<int>(flat.begin() + order, flat.begin() + 2 * order));			// a1
		chain_ids.push_back(1);
		for (int i = 2; i <= pairs; i++)
		{
			int	b_start = 2 * (i - 1) * order;
			int	a_start = b_start + order;
			pend.push_back(std::vector<int>(flat.begin() + b_start, flat.begin() + a_start));		// b_i
			chain.push_back(std::vector<int>(flat.begin() + a_start, flat.begin() + a_start + order)); // a_i
			chain_ids.push_back(i);
		}
		if (has_odd)
		{
			int	start = (groups - 1) * order;
			pend.push_back(std::vector<int>(flat.begin() + start, flat.begin() + start + order));
		}

		// Insert pend elements in Jacobsthal order: 3, 5, 11, 21, ...
		// Inside each block, from the highest index down to the previous bound.
		int	prev = 1;	// b1 is already in the chain
		int	j_prev = 1;
		int	j_cur = 3;
		while (prev < total_b)
		{
			int	cur = (j_cur < total_b) ? j_cur : total_b;
			for (int i = cur; i > prev; i--)
			{
				const std::vector<int>&	b = pend[i - 2];
				int						value = b.back();

				// Search bound: position of a_i in the chain.
				// The odd leftover has no a_i, so it searches the whole chain.
				int	bound = (int)chain.size();
				if (i <= pairs)
				{
					for (int k = 0; k < (int)chain.size(); k++)
					{
						if (chain_ids[k] == i && k != 0 && chain_ids[k] == i)
						{
							bound = k;
							break;
						}
					}
				}

				// Binary search in [0, bound)
				int	low = 0;
				int	high = bound;
				while (low < high)
				{
					int	mid = low + (high - low) / 2;
					if (chain[mid].back() < value)
						low = mid + 1;
					else
						high = mid;
				}

				chain.insert(chain.begin() + low, b);
				chain_ids.insert(chain_ids.begin() + low, i);
			}
			prev = cur;
			int	next = j_cur + 2 * j_prev;
			j_prev = j_cur;
			j_cur = next;
		}

		// Rebuild: chain groups, then the trailing elements that didn't fill a group
		std::vector<int>	result;
		result.reserve(n);
		for (int i = 0; i < (int)chain.size(); i++)
			result.insert(result.end(), chain[i].begin(), chain[i].end());
		result.insert(result.end(), flat.begin() + groups * order, flat.end());

		v_of_v = v_to_vv(result);
	}
	print_v_of_v(v_of_v);
	return (0);
}