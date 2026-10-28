/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml-hote <ml-hote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 11:07:04 by ml-hote           #+#    #+#             */
/*   Updated: 2026/10/28 16:22:19 by ml-hote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <cstdlib>

class PmergeMe
{
private :
	std::vector<int>	v_sequence;
	std::list<int>		l_sequence;
public :
	//	Constructors / Destructor
	PmergeMe();
	PmergeMe(int len, char **input);
	~PmergeMe();
	
	int	test_recursion_vector(std::vector<int> v);
	void fordJohnson(std::vector<int> &v);
};

#endif