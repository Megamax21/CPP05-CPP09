/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml-hote <ml-hote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 00:28:51 by ml-hote           #+#    #+#             */
/*   Updated: 2026/10/22 00:28:52 by ml-hote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <string>
#include <iostream>
#include <fstream>
#include <map>
#include <cstdlib>

class BitcoinExchange
{
private:
	std::map<int, float> datamap;
public:
	BitcoinExchange();
	~BitcoinExchange();
	int		convertLineToDate(std::string line);
	float	convertLineToValue(std::string line);
	float	checkForValue(int date);
	int		parseLine(std::string line);
	void	lineErrorPrinting(int i);
	void	convertInput(std::string file_name);
	void	rewriteInputLine(std::string line);
};

#endif