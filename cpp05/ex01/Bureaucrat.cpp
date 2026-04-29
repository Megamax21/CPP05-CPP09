/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml-hote <ml-hote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 14:20:39 by ml-hote           #+#    #+#             */
/*   Updated: 2026/04/29 16:29:49 by ml-hote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.get_name()), grade(other.get_grade())
{
	std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	std::cout << "Bureaucrat copy assignment called" <<std::endl;
	if (this == &other)
		return(*this);
	this->grade = other.get_grade();
	return (*this);
}

void		Bureaucrat::decr_grade()
{
	if (this->grade == 150)
		throw(GradeTooLow);
	else
		this->grade++;
}

void		Bureaucrat::incr_grade()
{
	if (this->grade == 1)
		throw(GradeTooHigh);
	else
		this->grade--;
}

int			Bureaucrat::get_grade() const
{
	return (this->grade);
}

std::string	Bureaucrat::get_name() const
{
	return (this->name);
}

Bureaucrat::Bureaucrat() : name("John Doe"), grade(150)
{
	std::cout << "A Bureaucrat was created" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade)
{
	if (grade < 1)
		throw(GradeTooHigh);
	if (grade > 150)
		throw(GradeTooLow);
	std::cout << "A Bureaucrat '"<< name <<" (" << grade << ")' was created" << std::endl;
}

Bureaucrat::~Bureaucrat() { std::cout << "A Bureaucrat was destroyed" << std::endl; }

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj)
{
	os << obj.get_name() << ", bureaucrat grade " << obj.get_grade();
	return os;
}
