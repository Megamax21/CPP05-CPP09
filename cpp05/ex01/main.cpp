/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml-hote <ml-hote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 12:53:11 by ml-hote           #+#    #+#             */
/*   Updated: 2026/04/29 16:54:59 by ml-hote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Form.hpp"

int main(void)
{
	std::cout << "╔════════════════════════════════════════════════════════════╗" << std::endl;
	std::cout << "║         CPP05-EX01 FORM AND BUREAUCRAT TESTS               ║" << std::endl;
	std::cout << "╚════════════════════════════════════════════════════════════╝" << std::endl;

	std::cout << "\n=== TEST 1: Valid Form Creation ===" << std::endl;
	try
	{
		Form f1("Tax Form A", 75, 50);
		std::cout << "Created: " << f1 << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Unexpected exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== TEST 2: Form with Grade 1 (Highest) ===" << std::endl;
	try
	{
		Form f2("Presidential Order", 1, 1);
		std::cout << "Created: " << f2 << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Unexpected exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== TEST 3: Form with Grade 150 (Lowest) ===" << std::endl;
	try
	{
		Form f3("Basic Memo", 150, 150);
		std::cout << "Created: " << f3 << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Unexpected exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== TEST 4: Form with Invalid Sign Grade (0) ===" << std::endl;
	try
	{
		Form f4("Invalid Form 1", 50, 0);
	}
	catch (const Form::GradeTooHighException& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Unexpected exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== TEST 5: Form with Invalid Sign Grade (151) ===" << std::endl;
	try
	{
		Form f5("Invalid Form 2", 50, 151);
	}
	catch (const Form::GradeTooLowException& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Unexpected exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== TEST 6: Form with Invalid Exec Grade (0) ===" << std::endl;
	try
	{
		Form f6("Invalid Form 3", 0, 50);
	}
	catch (const Form::GradeTooHighException& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Unexpected exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== TEST 7: Form with Invalid Exec Grade (151) ===" << std::endl;
	try
	{
		Form f7("Invalid Form 4", 151, 50);
	}
	catch (const Form::GradeTooLowException& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Unexpected exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== TEST 8: Default Form Constructor ===" << std::endl;
	try
	{
		Form f8;
		std::cout << "Created: " << f8 << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Unexpected exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== TEST 9: Form Copy Constructor ===" << std::endl;
	try
	{
		Form f9("Report Form", 100, 75);
		Form f9_copy(f9);
		std::cout << "Original: " << f9 << std::endl;
		std::cout << "Copy: " << f9_copy << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Unexpected exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== TEST 10: Form Assignment Operator ===" << std::endl;
	try
	{
		Form f10("Form Alpha", 80, 60);
		Form f10_assign("Form Beta", 120, 100);
		std::cout << "Before assignment: " << f10_assign << std::endl;
		f10_assign = f10;
		std::cout << "After assignment: " << f10_assign << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Unexpected exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== TEST 11: Bureaucrat Signing Form (Success) ===" << std::endl;
	try
	{
		Bureaucrat b1("Alice", 50);
		Form f11("Document A", 75, 40);
		std::cout << "Initial: " << f11 << std::endl;
		f11.beSigned(b1);
		std::cout << "After signing: " << f11 << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Unexpected exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== TEST 12: Bureaucrat Signing Form (Grade Too Low) ===" << std::endl;
	try
	{
		Bureaucrat b2("Bob", 100);
		Form f12("Restricted Document", 50, 30);
		std::cout << "Initial: " << f12 << std::endl;
		f12.beSigned(b2);
		std::cout << "After signing: " << f12 << std::endl;
	}
	catch (const Form::GradeTooLowException& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Unexpected exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== TEST 13: Multiple Bureaucrats with Different Grades ===" << std::endl;
	try
	{
		Bureaucrat b3("Charlie", 10);
		Bureaucrat b4("Diana", 50);
		Bureaucrat b5("Eve", 150);
		Form f13("Executive Order", 50, 30);
		
		std::cout << "Initial: " << f13 << std::endl;
		try
		{
			f13.beSigned(b5);  // Grade too low
		}
		catch (const Form::GradeTooLowException& e)
		{
			std::cout << "Eve cannot sign (grade too low)" << std::endl;
		}
		
		try
		{
			f13.beSigned(b4);  // Grade too low
		}
		catch (const Form::GradeTooLowException& e)
		{
			std::cout << "Diana cannot sign (grade too low)" << std::endl;
		}
		
		f13.beSigned(b3);  // Should succeed
		std::cout << "Final: " << f13 << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Unexpected exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== TEST 14: Bureaucrat at Boundary Grade ===" << std::endl;
	try
	{
		Bureaucrat b6("Frank", 45);
		Form f14("Boundary Form", 75, 45);
		std::cout << "Bureaucrat grade: " << b6.get_grade() << std::endl;
		std::cout << "Form sign grade: " << f14.get_sign_grade() << std::endl;
		std::cout << "Initial: " << f14 << std::endl;
		f14.beSigned(b6);
		std::cout << "After signing: " << f14 << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Unexpected exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== TEST 15: Multiple Forms Signed by Same Bureaucrat ===" << std::endl;
	try
	{
		Bureaucrat b7("Grace", 30);
		Form f15a("Form X", 50, 25);
		Form f15b("Form Y", 75, 40);
		Form f15c("Form Z", 100, 50);
		
		std::cout << "Attempting to sign three forms..." << std::endl;
		
		try
		{
			f15a.beSigned(b7);
			std::cout << "Signed: " << f15a << std::endl;
		}
		catch (const Form::GradeTooLowException& e)
		{
			std::cout << "Failed to sign Form X" << std::endl;
		}
		
		try
		{
			f15b.beSigned(b7);
			std::cout << "Signed: " << f15b << std::endl;
		}
		catch (const Form::GradeTooLowException& e)
		{
			std::cout << "Failed to sign Form Y" << std::endl;
		}
		
		try
		{
			f15c.beSigned(b7);
			std::cout << "Signed: " << f15c << std::endl;
		}
		catch (const Form::GradeTooLowException& e)
		{
			std::cout << "Failed to sign Form Z" << std::endl;
		}
	}
	catch (const std::exception& e)
	{
		std::cerr << "Unexpected exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== TEST 16: Form with Same Sign and Exec Grades ===" << std::endl;
	try
	{
		Form f16("Uniform Grade Form", 75, 75);
		std::cout << "Created: " << f16 << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Unexpected exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== TEST 17: Grade Edge Cases (1 and 150) ===" << std::endl;
	try
	{
		Bureaucrat b8("Henry", 1);
		Form f17("God Form", 1, 1);
		
		std::cout << "Highest grade bureaucrat: " << b8 << std::endl;
		std::cout << "Highest grade form: " << f17 << std::endl;
		f17.beSigned(b8);
		std::cout << "After signing: " << f17 << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Unexpected exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== TEST 18: Form Unsigned Status Check ===" << std::endl;
	try
	{
		Form f18("Pending Signature", 100, 80);
		std::cout << "Form is signed: " << (f18.get_is_signed() ? "Yes" : "No") << std::endl;
		std::cout << "Form details: " << f18 << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Unexpected exception: " << e.what() << std::endl;
	}

	std::cout << "\n╔════════════════════════════════════════════════════════════╗" << std::endl;
	std::cout << "║                     ALL TESTS COMPLETED                    ║" << std::endl;
	std::cout << "╚════════════════════════════════════════════════════════════╝" << std::endl;

	return (0);
}