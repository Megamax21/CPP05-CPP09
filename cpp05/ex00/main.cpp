/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml-hote <ml-hote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 12:53:11 by ml-hote           #+#    #+#             */
/*   Updated: 2026/04/28 14:48:51 by ml-hote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Bureaucrat.hpp"

int main(void)
{
	try
	{
		Bureaucrat yoa("Tom", 0);  // grade 0 is invalid → throws GradeTooLowException
	}
	catch (const Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	catch (const Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	return (0);
}