/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml-hote <ml-hote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 13:37:03 by ml-hote           #+#    #+#             */
/*   Updated: 2026/05/30 01:15:13 by ml-hote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <string>
#include <iostream>


template <typename T> 
class Array
{
private:
	T* elements;
	unsigned int array_size;
public:
	Array(); // Creates an empty array
	Array(unsigned int n); // Creates an array of n elements
	
};

#include "Array.tpp"
#endif