/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml-hote <ml-hote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 12:53:11 by ml-hote           #+#    #+#             */
/*   Updated: 2026/05/05 21:29:21 by ml-hote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Form.hpp"

int main(void)
{
	std::cout << "Tests for cpp05/ex01" << std::endl;
	{
		// working tests :
		Form	form1("Form1", 20, 10);
		Bureaucrat	bureau_test1("Small Admin", 1);
		
		std::cout << "WORKING TEST :\n"<<std::endl;
		std::cout << "Form 1 is : "<< form1 <<" Bureaucrat : " << bureau_test1 << std::endl << std::endl;
		std::cout << "sign form method called !!!" << std::endl;
		bureau_test1.sign_form(form1);
		

		Form	form3("Form3", 20, 10);
		Bureaucrat	bureau_test3("Admin", 1);
		std::cout << "Form 3 is : "<< form3 <<" Bureaucrat : " << bureau_test3 << std::endl << std::endl;
		std::cout << "sign form method called !!!" << std::endl;
		bureau_test3.sign_form(form3);
		
	}
	{ 
		try
		{
			std::cout << std::endl << std::endl;
			// Grade too low
			std::cout << "Case of grade too low !" <<std::endl;
			Form	form2("Form2", 50, 40);
			Bureaucrat	bureau_test2("Intermediate worker", 70);
			std::cout << "Form 2 is : "<< form2 <<" Bureaucrat : " << bureau_test2 << std::endl << std::endl;
			std::cout << "sign form method called !!!" <<std::endl;
			bureau_test2.sign_form(form2);
		}
		catch (const std::exception& e)
		{
			std::cerr << "Unexpected exception: " << e.what() << std::endl;
		}

	}
 
	return (0);
}