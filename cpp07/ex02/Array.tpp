/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml-hote <ml-hote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 19:09:18 by ml-hote           #+#    #+#             */
/*   Updated: 2026/06/09 12:10:16 by ml-hote          ###   ########.fr       */
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

template <typename T>
Array<T>::~Array()
{
	delete[] this->elements;
	std::cout << "Array destructor called" << std::endl;
};

template <typename T>
T& Array<T>::operator[](int index)
{
	if (index < 0 || static_cast<unsigned int>(index) >= this->array_size)
		throw Array<T>::OutOfBoundException();
	return (elements[index]);
};

template <typename T>
const T& Array<T>::operator[](int index) const
{
	if (index < 0 || static_cast<unsigned int>(index) >= this->array_size)
		throw Array<T>::OutOfBoundException();
	return (elements[index]);
};

template <typename T>
unsigned int	Array<T>::get_size() const
{
	return this->array_size;
};

template <typename T>
const char* Array<T>::OutOfBoundException::what() const throw()
{
	return "Array: index out of bounds";
};