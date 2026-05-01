/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml-hote <ml-hote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 12:53:11 by ml-hote           #+#    #+#             */
/*   Updated: 2026/05/01 16:33:29 by ml-hote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <sstream>

int main(void)
{
	std::cout << "╔════════════════════════════════════════════════════════════╗" << std::endl;
	std::cout << "║         CPP05-EX02 ABSTRACT FORMS TESTS                    ║" << std::endl;
	std::cout << "╚════════════════════════════════════════════════════════════╝" << std::endl;

	// ============ PRESIDENTIAL PARDON FORM TESTS ============
	std::cout << "\n\n█████ PRESIDENTIAL PARDON FORM TESTS █████\n" << std::endl;

	std::cout << "TEST 1: Create and Display PresidentialPardonForm" << std::endl;
	try
	{
		PresidentialPardonForm ppf("Alice");
		std::cout << ppf << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\nTEST 2: Bureaucrat with Grade 5 Signs PresidentialPardonForm" << std::endl;
	try
	{
		Bureaucrat boss("Boss", 5);
		PresidentialPardonForm ppf2("Bob");
		std::cout << "Before signing: " << ppf2 << std::endl;
		boss.signForm(ppf2);
		std::cout << "After signing: " << ppf2 << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\nTEST 3: Bureaucrat with Grade 6 Tries to Sign (Should Fail)" << std::endl;
	try
	{
		Bureaucrat mid("Mid-level", 6);
		PresidentialPardonForm ppf3("Charlie");
		mid.signForm(ppf3);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\nTEST 4: Execute PresidentialPardonForm (Grade 25 to execute)" << std::endl;
	try
	{
		Bureaucrat executor("Executive", 24);
		PresidentialPardonForm ppf4("David");
		executor.signForm(ppf4);
		executor.executeForm(ppf4);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\nTEST 5: Execute PresidentialPardonForm (Grade 26 - Should Fail)" << std::endl;
	try
	{
		Bureaucrat poor_executor("Poor Executor", 26);
		PresidentialPardonForm ppf5("Eve");
		poor_executor.signForm(ppf5);
		poor_executor.executeForm(ppf5);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	// ============ ROBOTOMY REQUEST FORM TESTS ============
	std::cout << "\n\n█████ ROBOTOMY REQUEST FORM TESTS █████\n" << std::endl;

	std::cout << "TEST 6: Create and Display RobotomyRequestForm" << std::endl;
	try
	{
		RobotomyRequestForm rrf("Frank");
		std::cout << rrf << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\nTEST 7: Bureaucrat with Grade 72 Signs RobotomyRequestForm" << std::endl;
	try
	{
		Bureaucrat signer("Signer", 72);
		RobotomyRequestForm rrf2("Grace");
		std::cout << "Before signing: " << rrf2 << std::endl;
		signer.signForm(rrf2);
		std::cout << "After signing: " << rrf2 << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\nTEST 8: Bureaucrat with Grade 73 Tries to Sign (Should Fail)" << std::endl;
	try
	{
		Bureaucrat weak_signer("Weak Signer", 73);
		RobotomyRequestForm rrf3("Henry");
		weak_signer.signForm(rrf3);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\nTEST 9: Execute RobotomyRequestForm Multiple Times (50% Success Rate)" << std::endl;
	try
	{
		Bureaucrat robot_exec("Robot Executive", 45);
		for (int i = 0; i < 3; i++)
		{
			std::stringstream ss;
			ss << i;
			RobotomyRequestForm rrf4("Subject_" + ss.str());
			robot_exec.signForm(rrf4);
			robot_exec.executeForm(rrf4);
		}
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\nTEST 10: Execute RobotomyRequestForm (Grade 46 - Should Fail)" << std::endl;
	try
	{
		Bureaucrat weak_exec("Weak Exec", 46);
		RobotomyRequestForm rrf5("Iris");
		weak_exec.signForm(rrf5);
		weak_exec.executeForm(rrf5);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	// ============ SHRUBBERY CREATION FORM TESTS ============
	std::cout << "\n\n█████ SHRUBBERY CREATION FORM TESTS █████\n" << std::endl;

	std::cout << "TEST 11: Create and Display ShrubberyCreationForm" << std::endl;
	try
	{
		ShrubberyCreationForm scf("Garden");
		std::cout << scf << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\nTEST 12: Bureaucrat with Grade 145 Signs ShrubberyCreationForm" << std::endl;
	try
	{
		Bureaucrat gardener("Gardener", 145);
		ShrubberyCreationForm scf2("Park");
		std::cout << "Before signing: " << scf2 << std::endl;
		gardener.signForm(scf2);
		std::cout << "After signing: " << scf2 << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\nTEST 13: Bureaucrat with Grade 146 Tries to Sign (Should Fail)" << std::endl;
	try
	{
		Bureaucrat lazy("Lazy Worker", 146);
		ShrubberyCreationForm scf3("Forest");
		lazy.signForm(scf3);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\nTEST 14: Execute ShrubberyCreationForm (Grade 137 to execute)" << std::endl;
	try
	{
		Bureaucrat master("Master Gardener", 137);
		ShrubberyCreationForm scf4("Backyard");
		master.signForm(scf4);
		master.executeForm(scf4);
		std::cout << "File created successfully!" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\nTEST 15: Execute ShrubberyCreationForm (Grade 138 - Should Fail)" << std::endl;
	try
	{
		Bureaucrat apprentice("Apprentice", 138);
		ShrubberyCreationForm scf5("Field");
		apprentice.signForm(scf5);
		apprentice.executeForm(scf5);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	// ============ EDGE CASES AND SPECIAL TESTS ============
	std::cout << "\n\n█████ EDGE CASES AND SPECIAL TESTS █████\n" << std::endl;

	std::cout << "TEST 16: Try to Execute Unsigned Form" << std::endl;
	try
	{
		Bureaucrat strong("Strong Bureaucrat", 1);
		PresidentialPardonForm ppf_unsigned("Unsigned Target");
		std::cout << "Trying to execute unsigned form..." << std::endl;
		strong.executeForm(ppf_unsigned);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\nTEST 17: Copy Constructor Test" << std::endl;
	try
	{
		PresidentialPardonForm ppf_original("Original");
		PresidentialPardonForm ppf_copy(ppf_original);
		std::cout << "Original: " << ppf_original << std::endl;
		std::cout << "Copy: " << ppf_copy << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\nTEST 18: Assignment Operator Test" << std::endl;
	try
	{
		RobotomyRequestForm rrf_original("Original Target");
		RobotomyRequestForm rrf_assigned("Assigned Target");
		std::cout << "Before assignment: " << rrf_assigned << std::endl;
		rrf_assigned = rrf_original;
		std::cout << "After assignment: " << rrf_assigned << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\nTEST 19: Top Grade Bureaucrat (Grade 1) Can Execute All Forms" << std::endl;
	try
	{
		Bureaucrat president("President", 1);
		
		PresidentialPardonForm ppf_boss("Boss");
		RobotomyRequestForm rrf_subject("Subject");
		ShrubberyCreationForm scf_grounds("Grounds");

		president.signForm(ppf_boss);
		president.executeForm(ppf_boss);

		president.signForm(rrf_subject);
		president.executeForm(rrf_subject);

		president.signForm(scf_grounds);
		president.executeForm(scf_grounds);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\nTEST 20: Bottom Grade Bureaucrat (Grade 150) Cannot Sign Anything" << std::endl;
	try
	{
		Bureaucrat intern("Intern", 150);
		
		PresidentialPardonForm ppf_test("Test");
		RobotomyRequestForm rrf_test("Test");
		ShrubberyCreationForm scf_test("Test");

		intern.signForm(ppf_test);
		intern.signForm(rrf_test);
		intern.signForm(scf_test);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n\n╔════════════════════════════════════════════════════════════╗" << std::endl;
	std::cout << "║                    ALL TESTS COMPLETED                      ║" << std::endl;
	std::cout << "╚════════════════════════════════════════════════════════════╝" << std::endl;

	return (0);
}
