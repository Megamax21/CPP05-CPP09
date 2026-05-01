/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml-hote <ml-hote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 13:45:00 by ml-hote           #+#    #+#             */
/*   Updated: 2026/05/01 16:29:18 by ml-hote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
	: AForm("Presidential Pardon", 25, 5), target("Unknown")
{
	std::cout << "PresidentialPardonForm default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
	: AForm("Presidential Pardon", 25, 5), target(target)
{
	std::cout << "PresidentialPardonForm constructor called for target: " << target << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
	: AForm(other), target(other.target)
{
	std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	(void)other;
	std::cout << "PresidentialPardonForm copy assignment called" << std::endl;
	return (*this);
}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
	if (executor.get_grade() > this->get_exec_grade())
	{
		throw AForm::GradeTooLow;
	}
	std::cout << executor.get_name() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

std::string const & PresidentialPardonForm::getTarget() const
{
	return (this->target);
}
