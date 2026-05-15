/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml-hote <ml-hote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 19:47:24 by ml-hote           #+#    #+#             */
/*   Updated: 2026/05/15 03:11:14 by ml-hote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

void identify(Base* p)
{
	A* a1 = (dynamic_cast<A*>(p));
	B* b1 = (dynamic_cast<B*>(p));
	C* c1 = (dynamic_cast<C*>(p));
	std::cout << "Base *p : ";
	if (a1)
		std::cout << "A" << std::endl;
	if (b1)
		std::cout << "B" << std::endl;
	if (c1)
		std::cout << "C" << std::endl;
}
/* What is catch(...) ?
	The catch (...) handler matches exceptions of any type. If present,
	it can only be the last handler in a handler sequence.
*/
void identify(Base &p)
{
	std::cout << "Base &p : ";
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return;
	}
	catch (...) {}
	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return;
	}
	catch (...) {}
	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return;
	}
	catch (...) {}
}

Base*	generate(void)
{
	switch (rand()%3)
	{
	case 0:
		return (new A);
	case 1:
		return (new B);
	case 2:
		return (new C);
	}
	return (new Base);
}

