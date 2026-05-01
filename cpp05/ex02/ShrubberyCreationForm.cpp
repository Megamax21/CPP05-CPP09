/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml-hote <ml-hote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 13:45:00 by ml-hote           #+#    #+#             */
/*   Updated: 2026/05/01 16:35:51 by ml-hote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <cstdlib>
#include <ctime>

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("Shrubbery Creation", 137, 145), target("Unknown")
{
	std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	: AForm("Shrubbery Creation", 137, 145), target(target)
{
	std::cout << "ShrubberyCreationForm constructor called for target: " << target << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	: AForm(other), target(other.target)
{
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	(void)other;
	std::cout << "ShrubberyCreationForm copy assignment called" << std::endl;
	return (*this);
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
	if (executor.get_grade() > this->get_exec_grade())
	{
		throw AForm::GradeTooLow;
	}
	
	std::string filename = this->target + "_shrubbery";
	std::ofstream file(filename.c_str());
	
	if (!file.is_open())
	{
		std::cerr << "Error: Could not create file " << filename << std::endl;
		return ;
	}
	
	srand(time(0));
	int tree_choice = rand() % 3;
	
	if (tree_choice == 0)
	{
		file << "                # |\n";
		file << "               # | #\n";
		file << "             # | # | #\n";
		file << "            # | # | # |\n";
		file << "          # | # | # | # |\n";
		file << "        # | # | # | # | # |\n";
		file << "       # | # | # | # | # | #\n";
		file << "      # | # | # | # | # | # |\n";
		file << "    # | # | # | # | # | # | # |\n";
		file << "  # | # | # | # | # | # | # | # |\n";
		file << "     |_|_|_|_|_|_|_|_|_|_|_|_|\n";
		file << "          |_______|_______|\n";
	}
	else if (tree_choice == 1)
	{
		file << "               # #### ####\n";
		file << "          ### \\/#|### |/####\n";
		file << "         ##\\/#/ \\||/##/_/##/_#\n";
		file << "       ###  \\/###|/ \\/ # ###\n";
		file << "     ##_\\_#\\_\\\\## | #/###_/_####\n";
		file << "    ## #### # \\ #| /  #### ##/##\n";
		file << "     __#_--###`  |{,###---###-~\n";
		file << "                   \\ }{\n";
		file << "                    }}{  \n";
		file << "                    }}{ \n";
		file << "               ejm  {{}  \n";
		file << "              , -=-~{ .-^- _\n";
	}
	else if (tree_choice == 2)
	{
		file << "          &&& &&  & &&\n";
		file << "      && &\\/&\\|& ()|/ @, &&\n";
		file << "      &\\/(/&/&||/& /_/)_&/_&\n";
		file << "   &() &\\/&|()|/&\\/ '\" %\" & ()\n";
		file << "  &_\\_&&_\\ |& |&&/&__%_/_& &&\n";
		file << "&&   && & &| &| /& & % ()& /&&\n";
		file << " ()&_---()&\\&\\|&&-&&--%---()~\n";
		file << "     &&     \\|||\n";
		file << "             |||\n";
		file << "             |||\n";
		file << "             |||\n";
		file << "       , -=-~  .-^- _\n";
	}
	
	file.close();
	std::cout << "Shrubbery for " << this->target << " has been created in " << filename << std::endl;
}

std::string const & ShrubberyCreationForm::getTarget() const
{
	return (this->target);
}

