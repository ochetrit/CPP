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
		_data = other._data;
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

	if (!getline(_fd, input))
		throw ExceptionOpen();
	while (getline(_fd, input))
	{
		_data.insert(std::make_pair(input.substr(0, 10), std::atof(&input[11])));
	}
}

void	BitcoinExchange::print_map()
{
	print("date,exchange_rate");
	for (std::map<std::string, double>::iterator it = _data.begin(); it != _data.end(); it++)
	{
		std::cout << it->first << ","; 
		if (10000 <= it->second && (static_cast<int>(it->second * 100) % 10))
			std::cout << std::fixed << std::setprecision(2) << it->second << std::endl;
		else
			print(it->second);
	}
}

const char	*BitcoinExchange::ExceptionDate::what() const throw()
{
	return "Invalid date format !";
}

const char	*BitcoinExchange::ExceptionValue::what() const throw()
{
	return "Value has to be between 0 and 1000";
}

const char	*BitcoinExchange::ExceptionOpen::what() const throw()
{
	return "Could not open the file...";
}