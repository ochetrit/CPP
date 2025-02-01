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

ScalarConverter::~ScalarConverter(){
	print("Destructor has been called");
}


bool	ScalarConverter::pseudo_literals(std::string arg)
{
	if (!arg.compare("-inf") || !arg.compare("-inff"))
	{
		print("char: impossible");
		print("int: impossible");
		print("float: -inff");
		print("double: -inf");
		return true;
	}
	else if (!arg.compare("+inf") || !arg.compare("+inff"))
	{
		print("char: impossible");
		print("int: impossible");
		print("float: +inff");
		print("double: +inf");
		return true;
	}
	else if (!arg.compare("nan") || !arg.compare("nanf"))
	{
		print("char: impossible");
		print("int: impossible");
		print("float: nanf");
		print("double: nan");
		return true;
	}
	return false;
}

void	ScalarConverter::convert_type(std::string arg)
{
	if (pseudo_literals(arg))
		return ;
	else if (is_char(arg))
		return arg_to_char(arg);
	else if (is_int(arg))
		return arg_to_int(arg);
	else if (is_float(arg))
		return arg_to_float(arg);
	else if (is_double(arg))
		return arg_to_double(arg);
	else
	{
		print("char: impossible");
		print("int: impossible");
		print("float: impossible");
		print("double: impossible");
	}
}

void	ScalarConverter::arg_to_char(std::string arg)
{
	char *endptr = NULL;
	char c; 
	c = std::strtol(arg.c_str(), &endptr, 10);

	if (c < 32 || c  == 127)
		print("char: Non displayable");
	else
		print("char: " << c);
	print("int: " << static_cast<int>(c));
	print("float: " << static_cast<float>(c) << ".0f");
	print("double: " << static_cast<double>(c) << ".0");
}

void	ScalarConverter::arg_to_int(std::string arg)
{
	char *endptr = NULL;
	int nb; 
	nb = std::strtol(arg.c_str(), &endptr, 10);

	if (nb == static_cast<char>(nb) && nb >= 0)
		return arg_to_char(arg);
	print("char: impossible");
	print("int: " << nb);
	print("float: " << std::fixed << std::setprecision(1) << static_cast<float>(nb) << "f");
	print("double: " << std::fixed << std::setprecision(1) << static_cast<double>(nb));
}

void	ScalarConverter::arg_to_float(std::string arg)
{
	char *endptr = NULL;
	float nb = std::strtod(arg.c_str(), &endptr);

	size_t precision = arg.length() - 2 - arg.find_first_of('.', 0);
	print(precision);
	if (nb == static_cast<char>(nb) && nb >= 0)
		return arg_to_char(arg);
	print("char: impossible");
	if (nb <= std::numeric_limits<int>::max() && nb >= std::numeric_limits<int>::min())
		print("int: "<< static_cast<int>(nb));
	else
		print("int: impossible");
	print(std::fixed << std::setprecision(precision) << "float: " << nb << "f");
	print("double: "  << std::fixed << std::setprecision(precision) << nb);
}


void	ScalarConverter::arg_to_double(std::string arg)
{
	double nb = std::atof(arg.c_str());

	size_t precision = arg.length() - 1 - arg.find_first_of('.', 0);
	print(precision);
	if (nb == static_cast<char>(nb) && nb >= 0)
		return arg_to_char(arg);
	print("char: impossible");
	if (nb <= std::numeric_limits<int>::max() + 1 && nb >= std::numeric_limits<int>::min())
		print("int: "<< static_cast<int>(nb));
	else
		print("int: impossible");
	if (precision == 0)
		precision++;
	print(std::fixed << std::setprecision(precision) << "float: " << nb << "f");
	print("double: "  << std::fixed << std::setprecision(precision) << nb);
}