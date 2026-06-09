/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml-hote <ml-hote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 19:09:18 by ml-hote           #+#    #+#             */
/*   Updated: 2026/06/09 23:33:18 by ml-hote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
Array<T>::Array() : elements(NULL), array_size(0)
{
	std::cout << "Array default constructor called" << std::endl;
}

template <typename T>
Array<T>::Array(const Array<T>& other) : elements(NULL), array_size(other.array_size)
{
	if (this->array_size > 0)
	{
		this->elements = new T[this->array_size]();
		for (unsigned int i = 0; i < this->array_size; ++i)
			this->elements[i] = other.elements[i];
	}
	std::cout << "Array copy constructor called" << std::endl;
}

template <typename T>
Array<T>::Array(unsigned int n) : elements(NULL), array_size(n)
{
	if (n > 0)
		elements = new T[n]();
	std::cout << "Array with " << n << " arg constructor called" << std::endl;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& other)
{
	if (this != &other)
	{
		T* new_elements = NULL;
		if (other.array_size > 0)
		{
			new_elements = new T[other.array_size]();
			for (unsigned int i = 0; i < other.array_size; ++i)
				new_elements[i] = other.elements[i];
		}
		delete[] this->elements;
		this->elements = new_elements;
		this->array_size = other.array_size;
	}
	std::cout << "Array assignment operator called" << std::endl;
	return (*this);
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
unsigned int	Array<T>::size() const
{
	return this->array_size;
};

template <typename T>
const char* Array<T>::OutOfBoundException::what() const throw()
{
	return "Array: index out of bounds";
};