/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml-hote <ml-hote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 12:53:11 by ml-hote           #+#    #+#             */
/*   Updated: 2026/05/12 20:44:55 by ml-hote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/PresidentialPardonForm.hpp"
#include "../headers/RobotomyRequestForm.hpp"
#include "../headers/ShrubberyCreationForm.hpp"
#include "../headers/Intern.hpp"
#include <sstream>

int main(void)
{
	srand(time(0));
	std::cout << "cpp05/ex03 test cases !\n\n" << std::endl;
	{
		{
			try
			{
				std::cout << "Intern creates two forms that get signed and executed by two bureaucrats" << std::endl;
				Intern someRandomIntern;
				AForm* rrf;
				AForm* scf;
				Bureaucrat bureau_exec("Steve", 45);
				Bureaucrat bureau_sign("Eric", 72);
				rrf = someRandomIntern.makeForm("robotomy request", "Bender");
				scf = someRandomIntern.makeForm("shrubbery creation", "Mario");
				bureau_sign.signForm(*rrf);
				bureau_exec.executeForm(*rrf);
				bureau_sign.signForm(*scf);
				bureau_exec.executeForm(*scf);
			}
			catch (const std::exception& e)
			{
				std::cerr << "Unexpected exception: " << e.what() << std::endl;
			}
			
		}
		{
			try
			{
				std::cout << "\n\nIntern creates a form that doesn't exist" << std::endl;
				Intern someRandomIntern;
				AForm* rrf;
				
				rrf = someRandomIntern.makeForm("nuggets fabrication", "Ronald");
			}
			catch (const std::exception& e)
			{
				std::cerr << "Unexpected exception: " << e.what() << std::endl;
			}
			
		}
	}
	return (0);
}
