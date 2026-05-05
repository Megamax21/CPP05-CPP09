/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml-hote <ml-hote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 13:45:00 by ml-hote           #+#    #+#             */
/*   Updated: 2026/05/05 21:33:38 by ml-hote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ShrubberyCreationForm.hpp"


ShrubberyCreationForm::ShrubberyCreationForm() : 
	AForm("Shrubbery Creation Form", 137, 145), target("Generic Target Name")
{
	std::cout << "Shrubbery Creation Form Constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :
	AForm("Shrubbery Creation Form", 137, 145), target(target)
{
	std::cout << "Shrubbery Creation Form Constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) :
	AForm(other)
{
	std::cout << "Shrubbery Creation Form Copy Constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "Shrubbery Creation Form Destructor called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	(void)other;
	std::cout << "Shrubbery Creation Form Copy Assignment called" << std::endl;
	return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor)
{
	if (this->get_is_signed())
	{		
		if (executor.get_grade() > this->get_exec_grade())
		{
			std::cout << "Executor's grade is too low" << std::endl;
			throw (GradeTooLow);
		}
		const std::string		file_name = this->target + "_shrubbery";
		std::ofstream	my_file(file_name.c_str());
		my_file <<	"       oooOOO$$$\n"
				<<	"     oooooO$a$$$$$$\n"
				<<	"    ooO@OOOO$$$$$$$$$\n"
				<<	"    oOOOOOOOOOa$$$$$\n"
				<<	"   OOOOOOOOOa$a$@$$$$\n"
				<<	"     ooOOO@$$a$$$$$\n"
				<<	"       oOOO$$$$$$\n"
				<<	"           ++\n"
				<<	"           ++\n"
				<<	"           =+=\n"
				<<	"         =-+=-=\n";
		my_file.close();
		std::cout << executor.get_name() << " executed Shrubbery Creation Form for target " << this->target << std::endl;
	}
	else
	{
		std::cout << "Can't execute an unsigned Form !" << std::endl;
	}
	
}

std::string ShrubberyCreationForm::get_target() const
{
	return (this->target);
}
