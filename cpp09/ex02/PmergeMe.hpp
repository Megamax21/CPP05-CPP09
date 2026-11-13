/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml-hote <ml-hote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 11:07:04 by ml-hote           #+#    #+#             */
/*   Updated: 2026/11/13 18:52:18 by ml-hote          ###   ########.fr       */
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
	std::vector<std::vector<int> >	v_a;
	std::vector<std::vector<int> >	v_b;
	std::list<int>		l_sequence;
public :
	//	Constructors / Destructor
	PmergeMe();
	PmergeMe(int len, char **input);
	~PmergeMe();

	std::vector<int>				vv_to_v(std::vector<std::vector<int> > vv);
	std::vector<std::vector<int> >	v_to_vv(std::vector<int> v);
	int								fordJohnson(std::vector<std::vector<int> > v_of_v);
};

#endif