/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml-hote <ml-hote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 14:20:39 by ml-hote           #+#    #+#             */
/*   Updated: 2026/04/28 14:48:30 by ml-hote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("John Doe"), grade(150)
{
	std::cout << "A Bureaucrat was created" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade)
{
	if (grade < 1)
		throw(GradeTooHigh);
	if (grade > 150)
		throw(GradeTooLow);
	std::cout << "A Bureaucrat '"<< name <<" (" << grade << ")' was created" << std::endl;
}


Bureaucrat::~Bureaucrat() { std::cout << "A Bureaucrat was destroyed" << std::endl; }