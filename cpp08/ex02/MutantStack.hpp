/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml-hote <ml-hote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 12:39:31 by ml-hote           #+#    #+#             */
/*   Updated: 2026/06/22 14:16:17 by ml-hote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cstdlib>
#include <ctime>
#include <stack>
#include <list>
#include <deque>

template <typename T>
class MutantStack : public std::stack<T> {
public:
	MutantStack() {}
	~MutantStack() {}
	MutantStack(const MutantStack& copy) : std::stack<T>(copy) {}
	MutantStack& operator=(const MutantStack& other) {
		std::stack<T>::operator=(other);
		return *this;
	}

	typedef typename std::deque<T>::iterator iterator;
	typedef typename std::deque<T>::reverse_iterator reverse_iterator;
	typedef typename std::deque<T>::const_iterator const_iterator;

	iterator begin();
	iterator end();
	reverse_iterator rbegin();
	reverse_iterator rend();
	const_iterator cbegin() const;
	const_iterator cend() const;
};
#include "MutantStack.tpp"
#endif