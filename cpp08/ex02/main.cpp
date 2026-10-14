/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml-hote <ml-hote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 12:39:33 by ml-hote           #+#    #+#             */
/*   Updated: 2026/06/24 10:50:05 by ml-hote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}
	std::stack<int> s(mstack);
	std::cout << "---- additional tests ----" << std::endl;
	MutantStack<int> copy = mstack;
	std::cout << "Copied stack contents: ";
	for (MutantStack<int>::iterator it2 = copy.begin(); it2 != copy.end(); ++it2)
		std::cout << *it2 << " ";
	std::cout << std::endl;

	std::cout << "Reverse iteration: ";
	for (MutantStack<int>::reverse_iterator rit = mstack.rbegin(); rit != mstack.rend(); ++rit)
		std::cout << *rit << " ";
	std::cout << std::endl;

	std::cout << "Const iteration (cbegin/cend): ";
	for (MutantStack<int>::const_iterator cit = mstack.cbegin(); cit != mstack.cend(); ++cit)
		std::cout << *cit << " ";
	std::cout << std::endl;

	MutantStack<int> assigned;
	assigned = mstack;
	std::cout << "Assigned size: " << assigned.size() << std::endl;

	std::cout << "Popping all elements from assigned: ";
	while (!assigned.empty())
	{
		std::cout << assigned.top() << " ";
		assigned.pop();
	}
	std::cout << std::endl;

	return (0);
}