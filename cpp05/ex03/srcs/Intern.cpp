/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml-hote <ml-hote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 12:14:19 by ml-hote           #+#    #+#             */
/*   Updated: 2026/05/12 14:49:07 by ml-hote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/Intern.hpp"

int	parseName(std::string name)
{
	std::string names[]= {"shrubbery creation", "presidential pardon", "robotomy request"};
	for (int i = 0; i < 3; i++)
	{
		if (name == names[i])
			return (i);
	}
	return (-1);
}

Intern::Intern(/* args */)
{
	std::cout << "Intern default constructor called" << std::endl;
}

Intern::~Intern()
{
	std::cout << "Intern default destructor called" << std::endl;
}

AForm	*Intern::makeForm(std::string name, std::string target)
{
	AForm *form;
	switch (parseName(name))
	{
	case -1:
		std::cout << "Provided form name doesn't exist !" << std::endl;
		return(NULL);
		break;
	case 0:
		form = new ShrubberyCreationForm(target); 
		std::cout << "Intern creates " << form;
		return (form);
		break;
	case 1:
		form = new PresidentialPardonForm(target); 
		std::cout << "Intern creates " << form;
		return ((AForm *)form);
		break;
	case 2:
		form = new RobotomyRequestForm(target); 
		std::cout << "Intern creates " << form;
		return ((AForm *)form);
		break;
	}
	return (NULL);
}
