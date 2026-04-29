/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml-hote <ml-hote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 12:30:19 by ml-hote           #+#    #+#             */
/*   Updated: 2026/04/29 16:59:56 by ml-hote          ###   ########.fr       */
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

std::string	Form::get_name() const
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
Form::Form(std::string name, int exec_grade, int sign_grade)
	: name(name), sign_grade(sign_grade), exec_grade(exec_grade), is_signed(false)
{
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

void	Form::beSigned(Bureaucrat bureaucrat)
{
	if (bureaucrat.get_grade() > this->sign_grade)
	{
		std::cout <<  bureaucrat << " couldn't sign " << *this << "because their grade is too low !" << std::endl;
		throw (GradeTooLow);
	}
	else
	{
		this->is_signed = true;
		std::cout << bureaucrat << " signed " << *this << std::endl;
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