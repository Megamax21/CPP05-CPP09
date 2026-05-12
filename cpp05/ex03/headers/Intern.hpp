/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml-hote <ml-hote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 12:14:20 by ml-hote           #+#    #+#             */
/*   Updated: 2026/05/12 14:21:57 by ml-hote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
public:
	Intern(/* args */);
	~Intern();
	
	AForm	*makeForm(std::string name, std::string target);
};



#endif