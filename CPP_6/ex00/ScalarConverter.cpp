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
	size_t pos = (arg[0] == '+' || arg[0] == '-');

	if (arg.length() > 10 + pos)
		return (false);

	else if(arg.length() < 10 + pos)
	{
		for (size_t i = 0; i < arg.length(); i++)
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
	for (size_t i = 0; i < arg.length() - exp - pos; i++)
	{
		if (arg[i + exp + pos] > "38"[i])
			return false;
		else if (arg[i + exp + pos] < "38"[i])
			return true;
	}
	if (arg[exp] == '-')
	{
		pos = (arg[0] == '+' || arg[0] == '-');
		for (size_t i = 0; i < exp - 1; i++)
		{
			if (arg[pos + i] < "1.17549"[i])
				return false;
		}
	}
	else
	{
		pos = (arg[0] == '+' || arg[0] == '-');
		for (size_t i = 0; i < exp - 2; i++)
		{
			if (arg[pos + i] < "3.40282"[i])
				return false;
		}
	}
	return (true);
}

// ScalarConverter	

