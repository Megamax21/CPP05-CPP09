/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml-hote <ml-hote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 20:34:45 by ml-hote           #+#    #+#             */
/*   Updated: 2026/05/14 11:49:05 by ml-hote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>
#include <iostream>
#include <cstdlib>
#include <limits>
#include <cmath>
#include <iomanip>
#include <sstream>

void	ft_print_char(int input);
int		ft_print_float(std::string input);
int		ft_print_int(std::string input);
float	ft_print_double(std::string input);
int		parser(std::string input);

#endif