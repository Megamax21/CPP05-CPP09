/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml-hote <ml-hote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 12:30:19 by ml-hote           #+#    #+#             */
/*   Updated: 2026/05/05 21:32:22 by ml-hote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

int			Form::get_sign_grade() const
{
	return (this->sign_grade);
}

int			Form::get_exec_grade() const
{
	return (this->exec_grade);
}

std::string const &	Form::get_name() const
{
	return (this->name);
}

bool		Form::get_is_signed() const
{
	return (this->is_signed);
}

Form::Form()
	: name("Generic form name"), sign_grade(150), exec_grade(150), is_signed(false)
{
	std::cout << "Form constructor called" << std::endl;
}
Form::Form(std::string name, int sign_grade, int exec_grade)
	: name(name), sign_grade(sign_grade), exec_grade(exec_grade), is_signed(false)
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
	std::cout << "Form constructor called : " << name << "\nsign_grade :"<<sign_grade<<
			" | exec_grade :"<<exec_grade<<"\nsigned : " << is_signed << std::endl;
} // Constructor
Form::~Form()
{
	std::cout << "Form destructor called" << std::endl;
} // Destructor
Form& Form::operator=(const Form& other)
{
	(void)other;
	std::cout << "Form copy assignment called" << std::endl;
	return (*this);
} // Copy assignment operator overload

Form::Form(const Form& other) :
	name(other.get_name()), sign_grade(other.get_sign_grade()),
	exec_grade(other.get_exec_grade()), is_signed(false)
{
	std::cout << "Form Copy constructor called" << std::endl;
} // Copy Constructor

void	Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.get_grade() > this->sign_grade)
	{
		std::cout << "Bureaucrat " << bureaucrat.get_name() <<
			" couldn't sign form " << this->name << " because their grade is too low !" << std::endl;
		throw (bureaucrat.GradeTooLow);
	}
	else
	{
		this->is_signed = true;
		std::cout << bureaucrat << " signed " << this->name << std::endl;
	}
}


std::ostream& operator<<(std::ostream& os, const Form& obj)
{	
	os << obj.get_name() << ", form : grade to sign " << obj.get_sign_grade() 
		<< " and to execute " << obj.get_exec_grade() << ". ";
	if (obj.get_is_signed())
		os << "it is signed.";
	else
		os << "it is not signed.";
	return os;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "Form : Grade too high !";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Form : Grade too low !";
}