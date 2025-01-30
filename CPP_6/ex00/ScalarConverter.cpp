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
		return true;
	return false;
}

bool	ScalarConverter::is_int(std::string arg)
{

	size_t sgn = (arg[0] == '-');
	size_t pos = (arg[0] == '+' || arg[0] == '-');

	if (arg.length() > 10 + pos)
		return (false);

	else if(arg.length() < 10 + pos)
	{
		for (size_t i = 0; i < arg.length() - 1; i++)
		{
			if (!isdigit(arg[i + pos]))
				return (false);
		}
		return (true);
	}
	
	for (size_t i = 0; i < arg.length() - 1 - pos; i++)
	{
		if (arg[i + pos] > "214748364"[i] || !isdigit(arg[i + pos]))
			return (false);
	}
	if (arg[9 + pos] > '7' + (char)sgn)
		return (false);
	return (true);
}
 
bool ScalarConverter::is_float(std::string arg)
{
	size_t	pos = (arg[0] == '+'|| arg[0] == '-');
	size_t	dot_count = 0;
	size_t	exp_count = 0;
	size_t	f_count = 0;

	
	for (size_t i = pos; i < arg.length(); i++)
	{
		if (!isdigit(arg[i]))
		{
			if (arg[i] == '.')
			{
				dot_count++;
				if (!isdigit(arg[i + 1]))
					return false;
			}
			else if (arg[i] == 'f' || arg[i] == 'F')
			{
				f_count++;
				if (dot_count != 1 || arg[i + 1])
					return false;
			}
			else if (arg[i] == 'e')
			{
				exp_count++;
				if (dot_count != 1)
					return false;
				else if (arg[i + 1] == '-' || arg[i + 1] == '+')
					i++;
				if (!isdigit(arg[i + 1]))
					return (false);
			}
			else
				return false;
		}
	}
	if (dot_count != 1)
		return false;
	else if (exp_count == 1 && f_count != 0)
		return false;
	else if (f_count == 1 && exp_count != 0)
		return false;
	else if (f_count == 0 && exp_count == 0)
		return false;
	if (!check_overfloat(arg, exp_count))
		return false;
	return (true);
}

bool	ScalarConverter::check_overfloat(std::string arg, size_t exp)
{
	if (exp == 0)
		return true;
	for (size_t i = 0; i < arg.length(); i++)
	{
		if (arg[i] == 'e')
			exp = i + 1;
	}
	size_t pos = (arg[exp] == '+' || arg[exp] == '-');
	if (arg.length() < exp + pos + 2)
		return true;
	else if (arg.length() > exp + pos + 2)
		return false;
	for (size_t i = 0; i < arg.length() - exp - pos; i++)
	{
		if (arg[i + exp + pos] > "38"[i])
			return false;
	}
	pos = (arg[0] == '+' || arg[0] == '-');
	if (arg[exp] == '-')
	{
		for (size_t i = 0; i < exp - 1; i++)
		{
			if (arg[pos + i] < "1.17549"[i])
				return false;
		}
	}
	else
	{
		for (size_t i = 0; i < exp - 2; i++)
		{
			if (arg[pos + i] > "3.40282"[i])
				return false;
		}
	}
	return (true);
}

bool ScalarConverter::is_double(std::string arg)
{
	size_t	pos = (arg[0] == '+'|| arg[0] == '-');
	size_t	dot_count = 0;
	size_t	exp_count = 0;

	
	for (size_t i = pos; i < arg.length(); i++)
	{
		if (!isdigit(arg[i]))
		{
			if (arg[i] == '.')
			{
				dot_count++;
				if (!isdigit(arg[i + 1]))
					return false;
			}
			else if (arg[i] == 'e')
			{
				exp_count++;
				if (dot_count != 1)
					return false;
				else if (arg[i + 1] == '-' || arg[i + 1] == '+')
					i++;
				if (!isdigit(arg[i + 1]))
					return (false);
			}
			else
				return false;
		}
	}
	if (dot_count != 1)
		return false;
	if (!check_overdouble(arg, exp_count))
		return false;
	return (true);
}

bool	ScalarConverter::check_overdouble(std::string arg, size_t exp)
{
	if (exp == 0)
		return true;
	for (size_t i = 0; i < arg.length(); i++)
	{
		if (arg[i] == 'e')
			exp = i + 1;
	}
	size_t pos = (arg[exp] == '+' || arg[exp] == '-');
	print(arg.length() << exp << pos);
	if (arg.length() < exp + pos + 3)
		return true;
	else if (arg.length() > exp + pos + 3)
		return false;
	for (size_t i = 0; i < arg.length() - exp - pos; i++)
	{
		if (arg[i + exp + pos] > "308"[i])
			return false;
		else if (arg[i + exp + pos] < "308"[i])
			return true;
	}
	pos = (arg[0] == '+' || arg[0] == '-');
	if (arg[exp] == '-')
	{
		for (size_t i = 0; i < exp - 1; i++)
		{
			if (arg[pos + i] < "2.22507"[i])
				return false;
		}
	}
	else
	{
		for (size_t i = 0; i < exp - 2; i++)
		{
			if (arg[pos + i] > "1.79769"[i])
				return false;
		}
	}
	return (true);
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
		return ;
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
	print("float: " << static_cast<float>(nb) << ".0f");
	print("double: " << static_cast<double>(nb) << ".0");
}

void	ScalarConverter::arg_to_float(std::string arg)
{
	char *endptr = NULL;
	float nb;
	nb = std::strtod(arg.c_str(), &endptr);

	size_t precision = arg.length() - 2 - arg.find_first_of('.', 0);
	print(precision);
	if (nb == static_cast<char>(nb) && nb >= 0)
		return arg_to_char(arg);
	print("char: impossible");
	print("int: "<< static_cast<int>(nb));
	print("float: " << std::fixed << std::setprecision(precision) << nb << "f");
	print("double: "  << std::fixed << std::setprecision(precision) << nb);
}