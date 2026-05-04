/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml-hote <ml-hote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 13:45:00 by ml-hote           #+#    #+#             */
/*   Updated: 2026/05/04 15:52:39 by ml-hote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : 
	AForm("Presidential Pardon Form", 5, 25), target("Generic Target Name")
{
	std::cout << "Presidential Pardon Form Constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) :
	AForm("Presidential Pardon Form", 5, 25), target(target)
{
	std::cout << "Presidential Pardon Form Constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) :
	AForm(other)
{
	std::cout << "Presidential Pardon Form Copy Constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "Presidential Pardon Form Destructor called" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	(void)other;
	std::cout << "Presidential Pardon Form Copy Assignment called" << std::endl;
	return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const & executor)
{
	if (this->get_is_signed())
	{		
		if (executor.get_grade() > this->get_exec_grade())
		{
			std::cout << "Executor's grade is too low" << std::endl;
			throw (GradeTooLow);
		}
		std::cout << this->target << " has been pardoned by Zaphod Beeblebrox" << std::endl ;
		std::cout << executor.get_name() << " executed Presidential Pardon Form for target " << this->target << std::endl;
	}
	else
	{
		std::cout << "Can't execute an unsigned Form !" << std::endl;
	}
}

std::string PresidentialPardonForm::get_target() const
{
	return (this->target);
}