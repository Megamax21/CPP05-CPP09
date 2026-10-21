/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml-hote <ml-hote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 00:29:00 by ml-hote           #+#    #+#             */
/*   Updated: 2026/10/22 00:29:01 by ml-hote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <cstdlib>

class RPN
{
private :
	std::stack<int>	values; // that stack will stock the numeric values
	int				result;
	bool			error_catcher;
public :
	RPN();
	~ RPN();
	void	calculate(std::string expression);
	int		operate(char op); // op -> operator
	bool	get_error() const;
	int		get_result() const;
};

#endif