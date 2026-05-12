/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml-hote <ml-hote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 13:45:00 by ml-hote           #+#    #+#             */
/*   Updated: 2026/05/12 12:48:30 by ml-hote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/RobotomyRequestForm.hpp"


RobotomyRequestForm::RobotomyRequestForm() : 
	AForm("Robotomy Request", 45, 75), target("Generic Target Name")
{
	std::cout << "Robotomy Request Form Constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) :
	AForm("Robotomy Request", 45, 75), target(target)
{
	std::cout << "Robotomy Request Form Constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) :
	AForm(other)
{
	std::cout << "Robotomy Request Form Copy Constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "Robotomy Request Form Destructor called" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	(void)other;
	std::cout << "Robotomy Request Form Copy Assignment called" << std::endl;
	return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const & executor)
{
	if (this->get_is_signed())
	{
		std::cout << "* BRRRRRR * [LOUD AND UNBEARABLE DRILL NOISES]" << std::endl;
		if (executor.get_grade() > this->get_exec_grade())
		{
			std::cout << "Executor's grade is too low" << std::endl;
			throw (GradeTooLow);
		}
		if (rand()%2 == 0)
			std::cout << this->target << " received a successfull robotomy !!!" << std::endl;
		else
			std::cout << this->target << " robotomy failed..." << std::endl;
		std::cout << executor.get_name() << " executed Robotomy Request Form for target " << this->target << std::endl;
	}
	else
	{
		std::cout << "Can't execute an unsigned Form !" << std::endl;
	}
}

std::string RobotomyRequestForm::get_target() const
{
	return (this->target);
}