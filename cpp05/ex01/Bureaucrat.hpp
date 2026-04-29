/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml-hote <ml-hote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 14:20:43 by ml-hote           #+#    #+#             */
/*   Updated: 2026/04/29 16:31:29 by ml-hote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>

class Bureaucrat
{
private:
	const	std::string name;
	int		grade;
public:
	Bureaucrat();
	Bureaucrat(std::string name, int grade); // Constructor
	~Bureaucrat(); // Destructor
	Bureaucrat& operator=(const Bureaucrat& other); // Copy assignment operator overload
	Bureaucrat(const Bureaucrat& other); // Copy Constructor

	void		decr_grade();
	void		incr_grade();
	int			get_grade() const;
	std::string	get_name() const;

	// Exception classes
	class GradeTooHighException: public std::exception
	{
		public :
		virtual const char* what() const throw()
		{
			return "Grade too high !";
		}
	} GradeTooHigh;

	class GradeTooLowException: public std::exception
	{
		public :
		virtual const char* what() const throw()
		{
			return "Grade too low !";
		}
	} GradeTooLow;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj);

#endif