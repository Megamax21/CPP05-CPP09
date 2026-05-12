/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml-hote <ml-hote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 14:20:43 by ml-hote           #+#    #+#             */
/*   Updated: 2026/04/29 18:11:19 by ml-hote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"

class AForm
{
private:
	const std::string	name;
	const int			sign_grade;
	const int			exec_grade;
	bool				is_signed;
protected:
	AForm();
	AForm(std::string name, int exec_grade, int sign_grade); // Constructor
	AForm(const AForm& other); // Copy Constructor
public:
	virtual ~AForm(); // Destructor
	AForm& operator=(const AForm& other); // Copy assignment operator overload

	/* GETTERS */
	int			get_sign_grade() const;
	int			get_exec_grade() const;
	std::string const &	get_name() const;
	bool		get_is_signed() const;

	/* CLASS METHODS */
	void			beSigned(const Bureaucrat& bureaucrat);
	virtual void	execute(Bureaucrat const & executor) = 0;

	/* EXCEPTIONS */
	class GradeTooHighException: public std::exception
	{
		public :
		virtual const char* what() const throw();
	} GradeTooHigh;

	class GradeTooLowException: public std::exception
	{
		public :
		virtual const char* what() const throw();
	} GradeTooLow;
};

std::ostream& operator<<(std::ostream& os, const AForm& obj);

#endif