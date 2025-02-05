/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochetrit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:37:03 by ochetrit          #+#    #+#             */
/*   Updated: 2025/02/04 17:37:04 by ochetrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	print("Default constructor has been called");
}

BitcoinExchange::BitcoinExchange(std::string filename):_fd(filename.c_str()), _filename(filename)
{
	if (!_fd)
		throw ExceptionOpen();
	//print("Constructor has been called");
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other): _fd(other._filename.c_str()), _filename(other._filename)
{
	*this = other;
}

BitcoinExchange	&BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
	{
		_map = other._map;
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
	if (_fd)
		_fd.close();
	//print("Destructor of BitcoinExchange");
}

void    BitcoinExchange::fill_map()
{
	std::string input;
	t_date		date;

	if (!getline(_fd, input))
		throw ExceptionOpen();
	while (getline(_fd, input))
	{
		date.year = atoi(input.c_str());
		date.month = std::atoi(input.substr(5, 2).c_str());
		date.day = std::atoi(input.substr(8, 2).c_str());
		_map.insert(std::make_pair(date, std::atof(&input[11])));
	}
}

void	BitcoinExchange::print_map()
{
	print("date,exchange_rate");
	for (std::map<t_date, float>::iterator it = _map.begin(); it != _map.end(); it++)
	{
		std::cout << it->first.year << '-' << it->first.month << '-' << it->first.day << ','; 
		if (10000 <= it->second && (static_cast<int>(it->second * 100) % 10))
			std::cout << std::fixed << std::setprecision(2) << it->second << std::endl;
		else
			print(it->second);
	}
}

float	BitcoinExchange::coeff(t_date date)
{
	float	coeff = 0;

	for (std::map<t_date, float>::iterator it = _map.begin(); it != _map.end(); it++)
	{
		if (date < it->first)
			break ;
		coeff = it->second;
	}
	return coeff;
}

BitcoinExchange::ExceptionDate::~ExceptionDate() throw() {}

const char	*BitcoinExchange::ExceptionDate::what() const throw()
{
	return msg.c_str();
}

BitcoinExchange::ExceptionDate::ExceptionDate(std::string msg):msg("Error: bad date => " + msg){}

BitcoinExchange::ExceptionInput::~ExceptionInput() throw() {}

const char	*BitcoinExchange::ExceptionInput::what() const throw()
{
	return msg.c_str();
}

BitcoinExchange::ExceptionInput::ExceptionInput(std::string msg):msg("Error: bad input => " + msg){}

const char	*BitcoinExchange::ExceptionValue::what() const throw()
{
	return "Value has to be between 0 and 1000";
}


const char	*BitcoinExchange::ExceptionOpen::what() const throw()
{
	return "Could not open the file...";
}

const char	*BitcoinExchange::ExceptionIntMax::what() const throw()
{
	return "Error: too large a number.";
}

const char	*BitcoinExchange::ExceptionNegative::what() const throw()
{
	return "Error: not a positive number.";
}

const char	*BitcoinExchange::ExceptionNotaNumber::what() const throw()
{
	return "Error: not a number.";
}


bool	t_date::operator<(const s_date &other) const
{
	if (year != other.year)
		return year < other.year;
	if (month != other.month)
		return month < other.month;
	if (day != other.day)
		return day < other.day;
	return false;
}