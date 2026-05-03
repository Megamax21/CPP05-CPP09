/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml-hote <ml-hote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 12:30:19 by ml-hote           #+#    #+#             */
/*   Updated: 2026/04/29 18:11:43 by ml-hote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

int			AForm::get_sign_grade() const
{
	return (this->sign_grade);
}

int			AForm::get_exec_grade() const
{
	return (this->exec_grade);
}

std::string const &	AForm::get_name() const
{
	return (this->name);
}

bool		AForm::get_is_signed() const
{
	return (this->is_signed);
}

AForm::AForm()
	: name("Generic AForm name"), sign_grade(150), exec_grade(150), is_signed(false)
{
	if (sign_grade < exec_grade)
	{
		std::cout << "Sign grade is higher than Exec grade !" << std::endl;
		throw (this->GradeTooHigh);
	}
	if (sign_grade > 150 || exec_grade > 150)
	{
		std::cout << "Grade shouldn't be lower than 150 !" << std::endl;
		throw (this->GradeTooLow);
	}
	
	if (sign_grade <= 0 || exec_grade <= 0)
	{
		std::cout << "Grade shouldn't be higher than 1 !" << std::endl; 
		throw (this->GradeTooHigh);
	}
	std::cout << "AForm constructor called : " << name << "\nsign_grade :"<<sign_grade<<
			" | exec_grade :"<<exec_grade<<"\nsigned : " << is_signed << std::endl;
}

AForm::AForm(std::string name, int exec_grade, int sign_grade)
	: name(name), sign_grade(sign_grade), exec_grade(exec_grade), is_signed(false)
{
	std::cout << "AForm constructor called : " << name << "\nsign_grade :"<<sign_grade<<
			" | exec_grade :"<<exec_grade<<"\nsigned : " << is_signed << std::endl;
} // Constructor
AForm::~AForm()
{
	std::cout << "AForm destructor called" << std::endl;
} // Destructor
AForm& AForm::operator=(const AForm& other)
{
	(void)other;
	std::cout << "AForm copy assignment called" << std::endl;
	return (*this);
} // Copy assignment operator overload

AForm::AForm(const AForm& other) :
	name(other.get_name()), sign_grade(other.get_sign_grade()),
	exec_grade(other.get_exec_grade()), is_signed(false)
{
	std::cout << "AForm Copy constructor called" << std::endl;
} // Copy Constructor

void	AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.get_grade() > this->sign_grade)
	{
		std::cout << "Bureaucrat " << bureaucrat.get_name() <<
			" couldn't sign AForm " << this->name << " because their grade is too low !" << std::endl;
		throw (bureaucrat.GradeTooLow);
	}
	else
	{
		this->is_signed = true;
		std::cout << bureaucrat << " signed " << this->name << std::endl;
	}
}


std::ostream& operator<<(std::ostream& os, const AForm& obj)
{	
	os << obj.get_name() << ", AForm : grade to sign " << obj.get_sign_grade() 
		<< " and to execute " << obj.get_exec_grade() << ". ";
	if (obj.get_is_signed())
		os << "it is signed.";
	else
		os << "it is not signed.";
	return os;
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return "AForm : Grade too high !";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "AForm : Grade too low !";
}