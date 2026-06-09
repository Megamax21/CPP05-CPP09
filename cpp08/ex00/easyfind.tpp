/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml-hote <ml-hote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 23:52:47 by ml-hote           #+#    #+#             */
/*   Updated: 2026/06/10 00:48:18 by ml-hote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

template <typename T>
int len(T *array)
{
	int i = 0;
	while (array[i])
		i++;
	return (i);
}

template <typename T>
int easyfind(T *haystack, int needle)
{
	for (int i = 0 ; i < len(haystack) ; i++)
	{
		if (haystack[i] == needle)
			return (i);
	}
	return (-1);
}