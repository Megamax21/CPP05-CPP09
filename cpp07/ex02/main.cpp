/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml-hote <ml-hote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 13:37:05 by ml-hote           #+#    #+#             */
/*   Updated: 2026/06/09 12:04:52 by ml-hote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

void print_plus(int &a)
{
	std::cout << a+1 << std::endl;
}

int main( void )
{
	Array<int> arr; // default (no-arg) instance
	std::cout << "default array size: " << arr.get_size() << std::endl;
	try {
		std::cout << arr[2] << std::endl; // will throw for empty array
	} catch (const Array<int>::OutOfBoundException &e) {
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}
	return 0;
}