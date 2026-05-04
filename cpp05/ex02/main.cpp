/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml-hote <ml-hote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 12:53:11 by ml-hote           #+#    #+#             */
/*   Updated: 2026/05/04 15:41:22 by ml-hote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <sstream>

int main(void)
{
	srand(time(0));
	std::cout << "cpp05/ex02 test cases !\n\n" << std::endl;
	{
		{
			std::cout << "1. Presidential Pardon Form\n" << std::endl;
			
			std::cout << "Working cases\n\n" << std::endl;
			std::cout << "Exact grades\n" << std::endl;
			Bureaucrat bureaucrat_signer("Mr Signer", 25);
			Bureaucrat bureaucrat_executer("Mr Exec", 5);
			PresidentialPardonForm ppf1("Tobby");

			ppf1.beSigned(bureaucrat_signer);
			ppf1.execute(bureaucrat_executer);
		}
		{
			std::cout << "Grades higher then needed\n" << std::endl;
			Bureaucrat bureaucrat_signer("Mr Signer", 20);
			Bureaucrat bureaucrat_executer("Mr Exec", 1);
			PresidentialPardonForm ppf1("Tomtom");
			
			ppf1.beSigned(bureaucrat_signer);
			ppf1.execute(bureaucrat_executer);
		}
		{
			try 
			{
				std::cout << "\n\nFailing cases\n\n" <<std::endl;
				std::cout << "No signer\n" << std::endl;
				Bureaucrat bureaucrat_executer("Overconfident executer", 5);
				PresidentialPardonForm ppf1("Tomtom");
				
				ppf1.execute(bureaucrat_executer);
				
			}
			catch (const std::exception& e)
			{
				std::cerr << "Unexpected exception: " << e.what() << std::endl;
			}
		}
		{
			try 
			{
				std::cout << "\n\n" <<std::endl;
				std::cout << "Signer has grade too low\n" << std::endl;
				Bureaucrat bureaucrat_signer("The Low Grade Signer", 70);
				Bureaucrat bureaucrat_executer("The Executer", 5);
				PresidentialPardonForm ppf1("Tomtom");

				ppf1.beSigned(bureaucrat_signer);
				ppf1.execute(bureaucrat_executer);
				
			}
			catch (const std::exception& e)
			{
				std::cerr << "Unexpected exception: " << e.what() << std::endl;
			}
		}
		{
			std::cout << "2. Robotomy Request Form\n" << std::endl;
			
			std::cout << "Working cases\n\n" << std::endl;
			std::cout << "Exact grades\n" << std::endl;
			Bureaucrat bureaucrat_signer("Mr Signer", 25);
			Bureaucrat bureaucrat_executer("Mr Exec", 5);
			RobotomyRequestForm rrf1("Timmy");

			rrf1.beSigned(bureaucrat_signer);
			rrf1.execute(bureaucrat_executer);
		}
		{
			std::cout << "3. Shrubbery Creation Form\n" << std::endl;
			
			std::cout << "Working cases\n\n" << std::endl;
			std::cout << "Exact grades\n" << std::endl;
			Bureaucrat bureaucrat_signer("Mr Signer", 145);
			Bureaucrat bureaucrat_executer("Mr Exec", 137);
			ShrubberyCreationForm scf1("Tabby");

			scf1.beSigned(bureaucrat_signer);
			scf1.execute(bureaucrat_executer);
		}
	}
	return (0);
}
