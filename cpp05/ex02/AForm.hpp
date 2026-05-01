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

#ifndef AForm_HPP
#define AForm_HPP

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
public:
	virtual ~AForm(); // Destructor
	AForm& operator=(const AForm& other); // Copy assignment operator overload
	AForm(const AForm& other); // Copy Constructor

	/* GETTERS */
	virtual int			get_sign_grade() const;
	virtual int			get_exec_grade() const;
	virtual std::string const &	get_name() const;
	virtual bool		get_is_signed() const;

	/* CLASS METHODS */
	virtual void	beSigned(Bureaucrat bureaucrat);
	virtual void	execute(const Bureaucrat& executor) const = 0;	// Pure virtual function

	/* EXCEPTIONS */
	class GradeTooHighException: public std::exception
	{
		public :
		virtual const char* what() const throw()
		{
			return "AForm grade too high !";
		}
	} GradeTooHigh;

	class GradeTooLowException: public std::exception
	{
		public :
		virtual const char* what() const throw()
		{
			return "AForm grade too low !";
		}
	} GradeTooLow;
};

std::ostream& operator<<(std::ostream& os, const AForm& obj);

#endif