/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochetrit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 16:08:13 by ochetrit          #+#    #+#             */
/*   Updated: 2024/12/30 16:08:14 by ochetrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include <limits>
#include <cstdlib>
#include <iomanip>

#define print(x) std::cout << x << std::endl

class	ScalarConverter
{
	private :
	ScalarConverter();
	ScalarConverter(const ScalarConverter &other);

	public :
	~ScalarConverter();
	ScalarConverter	&operator=(const ScalarConverter &other);


	static bool is_char(std::string arg);
	static bool is_int(std::string arg);
	static bool is_float(std::string arg);
	static bool check_overfloat(std::string arg, size_t exp_count);
	static bool is_double(std::string arg);
	static bool check_overdouble(std::string arg, size_t exp_count);


	static bool	pseudo_literals(std::string arg);
	static void	convert_type(std::string arg);
	static void	arg_to_char(std::string arg);
	static void	arg_to_int(std::string arg);
	static void	arg_to_float(std::string arg);
	static void	arg_to_double(std::string arg);
};
