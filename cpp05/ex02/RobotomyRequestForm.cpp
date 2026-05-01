/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml-hote <ml-hote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 13:45:00 by ml-hote           #+#    #+#             */
/*   Updated: 2026/05/01 16:28:19 by ml-hote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("Robotomy Request", 45, 72), target("Unknown")
{
	std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
	: AForm("Robotomy Request", 45, 72), target(target)
{
	std::cout << "RobotomyRequestForm constructor called for target: " << target << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
	: AForm(other), target(other.target)
{
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	(void)other;
	std::cout << "RobotomyRequestForm copy assignment called" << std::endl;
	return (*this);
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
	if (executor.get_grade() > this->get_exec_grade())
	{
		throw AForm::GradeTooLow;
	}
	std::cout << "🔩 *BZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ* 🔩" << std::endl;
	srand(time(0));
	if (rand() % 2)
		std::cout << this->target << " has been successfully robotomized!" << std::endl;
	else
		std::cout << "Robotomy of " << this->target << " failed." << std::endl;
}

std::string const & RobotomyRequestForm::getTarget() const
{
	return (this->target);
}
