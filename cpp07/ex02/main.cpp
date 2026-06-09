/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml-hote <ml-hote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 13:37:05 by ml-hote           #+#    #+#             */
/*   Updated: 2026/06/09 23:33:18 by ml-hote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
bool expectEqual(const T& actual, const T& expected, const std::string& label)
{
	if (actual != expected)
	{
		std::cerr << "[FAIL] " << label << ": expected " << expected << ", got " << actual << std::endl;
		return false;
	}
	std::cout << "[PASS] " << label << std::endl;
	return true;
}

template <typename T>
bool expectOutOfBounds(Array<T>& array, int index, const std::string& label)
{
	try
	{
		(void)array[index];
	}
	catch (const std::exception&)
	{
		std::cout << "[PASS] " << label << std::endl;
		return true;
	}
	std::cerr << "[FAIL] " << label << ": expected exception" << std::endl;
	return false;
}

void print_plus(int &a)
{
	std::cout << a+1 << std::endl;
}

int main( void )
{
	int failures = 0;

	{
		Array<int> empty;
		failures += !expectEqual(empty.size(), 0u, "default constructor creates empty array");
		failures += !expectOutOfBounds(empty, 0, "empty array access throws");
	}

	{
		Array<int> values(5);
		failures += !expectEqual(values.size(), 5u, "size constructor stores requested length");
		for (unsigned int i = 0; i < values.size(); ++i)
			failures += !expectEqual(values[i], 0, "size constructor value-initializes int elements");

		for (unsigned int i = 0; i < values.size(); ++i)
			values[i] = static_cast<int>(i * 10);
		for (unsigned int i = 0; i < values.size(); ++i)
			failures += !expectEqual(values[i], static_cast<int>(i * 10), "subscript operator reads and writes elements");

		const Array<int>& const_values = values;
		failures += !expectEqual(const_values[2], 20, "const subscript operator provides read access");
		failures += !expectOutOfBounds(values, -1, "negative index throws");
		failures += !expectOutOfBounds(values, static_cast<int>(values.size()), "index equal to size throws");
	}

	{
		Array<int> original(3);
		original[0] = 1;
		original[1] = 2;
		original[2] = 3;

		Array<int> copied(original);
		failures += !expectEqual(copied.size(), original.size(), "copy constructor preserves size");
		failures += !expectEqual(copied[0], 1, "copy constructor copies first value");
		failures += !expectEqual(copied[1], 2, "copy constructor copies second value");
		failures += !expectEqual(copied[2], 3, "copy constructor copies third value");

		original[0] = 42;
		copied[1] = 99;
		failures += !expectEqual(original[0], 42, "copy constructor keeps arrays independent after source mutation");
		failures += !expectEqual(original[1], 2, "copy constructor keeps original unchanged after copy mutation");

		Array<int> assigned(1);
		assigned[0] = -5;
		assigned = original;
		failures += !expectEqual(assigned.size(), original.size(), "assignment operator copies size");
		failures += !expectEqual(assigned[0], 42, "assignment operator copies first value");
		failures += !expectEqual(assigned[1], 2, "assignment operator copies second value");
		failures += !expectEqual(assigned[2], 3, "assignment operator copies third value");

		original[1] = 77;
		assigned[2] = 88;
		failures += !expectEqual(assigned[1], 2, "assignment operator keeps arrays independent after source mutation");
		failures += !expectEqual(original[2], 3, "assignment operator keeps source unchanged after destination mutation");
	}

	if (failures == 0)
		std::cout << "All Array tests passed" << std::endl;
	else
		std::cerr << failures << " Array test(s) failed" << std::endl;
	return (failures == 0 ? 0 : 1);
}