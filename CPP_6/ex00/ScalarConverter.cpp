/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochetrit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 16:08:07 by ochetrit          #+#    #+#             */
/*   Updated: 2024/12/30 16:08:08 by ochetrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){
	print("Default constructor has been called.");
}

ScalarConverter::ScalarConverter(const ScalarConverter &other){
	print("Copy constructor has been called.");
	*this = other;
}

ScalarConverter	&ScalarConverter::operator=(const ScalarConverter &other){
	(void)other;
	return (*this);
}


bool	ScalarConverter::is_char(std::string arg)
{
	if (arg.length() == 1)
		return (true);
	return (false);
}

bool	ScalarConverter::is_int(std::string arg)
{

	size_t sgn = (arg[0] == '-');

	if (arg.length() > 10 + sgn)
		return (false);

	else if(arg.length() < 10 + sgn)
		return (true);
	for (size_t i = 0; i < arg.length() - 2; i++)
	{
		if (arg[i + sgn] > "214748364"[i])
			return (false);
	}
	if (arg[9 + sgn] > '7' + (char)sgn)
		return (false);
	return (true);
}
 
// ScalarConverter

// ScalarConverter	

