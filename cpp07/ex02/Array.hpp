/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml-hote <ml-hote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 13:37:03 by ml-hote           #+#    #+#             */
/*   Updated: 2026/06/09 23:53:34 by ml-hote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <string>
#include <iostream>
#include <exception>


template <typename T> 
class Array
{
private:
	T* elements;
	unsigned int array_size;
public:
	T& operator[](int index);
	const T& operator[](int index) const;
	Array(const Array& other);
	Array& operator=(const Array& other);
	~Array();
	Array(); // Creates an empty array
	Array(unsigned int n); // Creates an array of n elements
	
	unsigned int size() const;
	unsigned int get_size() const;
	class OutOfBoundException : public std::exception
	{
	public:
		const char* what() const throw();
	};
};

#include "Array.tpp"
#endif