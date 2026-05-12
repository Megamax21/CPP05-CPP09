/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml-hote <ml-hote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 12:53:11 by ml-hote           #+#    #+#             */
/*   Updated: 2026/05/12 14:49:44 by ml-hote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/PresidentialPardonForm.hpp"
#include "../headers/RobotomyRequestForm.hpp"
#include "../headers/ShrubberyCreationForm.hpp"
#include <sstream>

int main(void)
{
	srand(time(0));
	std::cout << "cpp05/ex03 test cases !\n\n" << std::endl;
	{
		{
			std::cout << "1. Intern Presidential Pardon Form\n" << std::endl;
			
			std::cout << "Working cases\n\n" << std::endl;
			std::cout << "Exact grades\n" << std::endl;
			Bureaucrat bureaucrat_signer("Mr Signer", 25);
			Bureaucrat bureaucrat_executer("Mr Exec", 5);
			PresidentialPardonForm ppf1("Tobby");

			ppf1.beSigned(bureaucrat_signer);
			ppf1.execute(bureaucrat_executer);
		}
	}
	return (0);
}
