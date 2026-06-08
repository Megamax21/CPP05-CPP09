/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml-hote <ml-hote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 19:09:18 by ml-hote           #+#    #+#             */
/*   Updated: 2026/05/30 01:20:10 by ml-hote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
Array<T>::Array() : elements(NULL), array_size(0)
{
	std::cout << "Array default constructor called" << std::endl;
}

template <typename T>
Array<T>::Array(unsigned int n) : elements(NULL), array_size(n)
{
	if (n > 0)
		elements = new T[n];
	std::cout << "Array with " << n << " arg constructor called" << std::endl;
}
/*
template <>
Array<int>::Array(unsigned int n) : elements(new int[n]), array_size(n)
{
	std::cout << "Array of" << n << " ints constructed" << std::endl;
}

template <>
Array<int>::Array() : elements(new int[0])
{
	std::cout << "Array of ints constructed" << std::endl;
}
*/
/*
template <>
Array<int>::Array(unsigned int n) : elements(new int[n]), array_size(n)
{
	std::cout << "Array of" << n << " ints constructed" << std::endl;
}

template <>
Array<int>::Array() : elements(new int[0])
{
	std::cout << "Array of ints constructed" << std::endl;
}
*/