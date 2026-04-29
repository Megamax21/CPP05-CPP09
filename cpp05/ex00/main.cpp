/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml-hote <ml-hote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 12:53:11 by ml-hote           #+#    #+#             */
/*   Updated: 2026/04/29 16:28:27 by ml-hote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Bureaucrat.hpp"

int main(void)
{
	std::cout << "=== TEST 1: Valid Bureaucrat Creation ===" << std::endl;
	try
	{
		Bureaucrat b1("Alice", 75);  // Valid grade
		std::cout << "Created: " << b1 << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Unexpected exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== TEST 2: Grade 1 (Highest) ===" << std::endl;
	try
	{
		Bureaucrat b2("Bob", 1);
		std::cout << "Created: " << b2 << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Unexpected exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== TEST 3: Grade 150 (Lowest) ===" << std::endl;
	try
	{
		Bureaucrat b3("Charlie", 150);
		std::cout << "Created: " << b3 << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Unexpected exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== TEST 4: Grade 0 (GradeTooHighException) ===" << std::endl;
	try
	{
		Bureaucrat b4("David", 0);
	}
	catch (const Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "\n=== TEST 5: Grade 151 (GradeTooLowException) ===" << std::endl;
	try
	{
		Bureaucrat b5("Eve", 151);
	}
	catch (const Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "\n=== TEST 6: Negative Grade (GradeTooHighException) ===" << std::endl;
	try
	{
		Bureaucrat b6("Frank", -5);
	}
	catch (const Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "\n=== TEST 7: Default Constructor ===" << std::endl;
	try
	{
		Bureaucrat b7;
		std::cout << "Created: " << b7 << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Unexpected exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== TEST 8: Copy Constructor ===" << std::endl;
	try
	{
		Bureaucrat b8("Grace", 50);
		Bureaucrat b8_copy(b8);
		std::cout << "Original: " << b8 << std::endl;
		std::cout << "Copy: " << b8_copy << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Unexpected exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== TEST 9: Assignment Operator ===" << std::endl;
	try
	{
		Bureaucrat b9("Henry", 100);
		Bureaucrat b9_assign("Ivy", 25);
		std::cout << "Before assignment: " << b9_assign << std::endl;
		b9_assign = b9;
		std::cout << "After assignment: " << b9_assign << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Unexpected exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== TEST 10: Increment Grade (incr_grade) ===" << std::endl;
	try
	{
		Bureaucrat b10("Jack", 50);
		std::cout << "Initial: " << b10 << std::endl;
		b10.incr_grade();
		std::cout << "After incr_grade(): " << b10 << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Unexpected exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== TEST 11: Decrement Grade (decr_grade) ===" << std::endl;
	try
	{
		Bureaucrat b11("Kate", 50);
		std::cout << "Initial: " << b11 << std::endl;
		b11.decr_grade();
		std::cout << "After decr_grade(): " << b11 << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Unexpected exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== TEST 12: Increment Grade at Boundary (Grade 1) ===" << std::endl;
	try
	{
		Bureaucrat b12("Liam", 1);
		std::cout << "At grade 1, trying to increment..." << std::endl;
		b12.incr_grade();
		std::cout << "After incr_grade(): " << b12 << std::endl;
	}
	catch (const Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Unexpected exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== TEST 13: Decrement Grade at Boundary (Grade 150) ===" << std::endl;
	try
	{
		Bureaucrat b13("Mia", 150);
		std::cout << "At grade 150, trying to decrement..." << std::endl;
		b13.decr_grade();
		std::cout << "After decr_grade(): " << b13 << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Unexpected exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== TEST 14: Multiple Increments Until Boundary ===" << std::endl;
	try
	{
		Bureaucrat b14("Noah", 5);
		std::cout << "Starting: " << b14 << std::endl;
		for (int i = 0; i < 5; i++)
		{
			b14.incr_grade();
			std::cout << "After incr_grade #" << (i + 1) << ": " << b14 << std::endl;
		}
	}
	catch (const Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Unexpected exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== TEST 15: Multiple Decrements Until Boundary ===" << std::endl;
	try
	{
		Bureaucrat b15("Olivia", 147);
		std::cout << "Starting: " << b15 << std::endl;
		for (int i = 0; i < 5; i++)
		{
			b15.decr_grade();
			std::cout << "After decr_grade #" << (i + 1) << ": " << b15 << std::endl;
		}
	}
	catch (const Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Unexpected exception: " << e.what() << std::endl;
	}

	return (0);
}