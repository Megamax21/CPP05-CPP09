/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml-hote <ml-hote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 14:20:43 by ml-hote           #+#    #+#             */
/*   Updated: 2026/04/29 18:11:19 by ml-hote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Form
{
private:
	const std::string	name;
	const int			sign_grade;
	const int			exec_grade;
	bool				is_signed;
public:
	Form();
	Form(std::string name, int exec_grade, int sign_grade); // Constructor
	~Form(); // Destructor
	Form& operator=(const Form& other); // Copy assignment operator overload
	Form(const Form& other); // Copy Constructor

	/* GETTERS */
	int			get_sign_grade() const;
	int			get_exec_grade() const;
	std::string const &	get_name() const;
	bool		get_is_signed() const;

	/* CLASS METHODS */
	void	beSigned(Bureaucrat bureaucrat);

	/* EXCEPTIONS */
	class GradeTooHighException: public std::exception
	{
		public :
		virtual const char* what() const throw()
		{
			return "Form grade too high !";
		}
	} GradeTooHigh;

	class GradeTooLowException: public std::exception
	{
		public :
		virtual const char* what() const throw()
		{
			return "Form grade too low !";
		}
	} GradeTooLow;
};

std::ostream& operator<<(std::ostream& os, const Form& obj);

#endif