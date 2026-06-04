/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml-hote <ml-hote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 13:37:03 by ml-hote           #+#    #+#             */
/*   Updated: 2026/05/15 14:52:27 by ml-hote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <string>
#include <iostream>

template <typename T>
void swap(T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
};
template <typename T>
T max(T a, T b)
{
	if (a > b)
		return (a);
	else
		return (b);
};
template <typename T>
T min(T a, T b)
{
	if (a < b)
		return (a);
	else
		return (b);
};

#endif