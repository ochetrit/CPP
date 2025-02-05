/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochetrit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:36:44 by ochetrit          #+#    #+#             */
/*   Updated: 2025/02/04 17:36:47 by ochetrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"


void	parse_date(t_date &date, std::string line);
float	parse_value(std::string line);
void	print_message(t_date date, float value, float coeff);

int main(int ac, char **av)
{
	if (ac == 1)
	{
		std::cerr << "I need a file as argument !" << std::endl;
		return 1;
	}
	else if (ac > 2)
	{
		std::cerr << "I need a file as argument !" << std::endl;
		return 2;
	}
	std::ifstream filename(av[1]);
	std::string	line;
	if (!getline(filename, line))
	{
		std::cerr << "Could not open the file..." << std::endl;
		return 4;
	}
	if (line.compare("date | value"))
	{
		std::cerr << "Invalid format at the beginning, I need you to fix it" << std::endl;
		return 5;
	}

	std::string data("data.csv");
	BitcoinExchange	bct(data.c_str());
	bct.fill_map();
	if (!filename)
	{
		std::cerr << "Could not open the file..." << std::endl;
		return 3;
	}

	
	while (getline(filename, line))
	{
		try
		{
			t_date	date;
			parse_date(date,line);
			float value = parse_value(line.substr(13, line.size()));
			print_message(date, value, bct.coeff(date));
		}
		catch(BitcoinExchange::ExceptionDate)
		catch(BitcoinExchange::ExceptionInput)
		catch(BitcoinExchange::ExceptionIntMax)
		catch(BitcoinExchange::ExceptionNegative)
		catch(BitcoinExchange::ExceptionNotaNumber)
	}
	return 0;
}

void	parse_date(t_date &date, std::string line)
{
	int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int	year, month, day;

	if (line.size() < 13)
		throw BitcoinExchange::ExceptionInput(line);

	if (line[4] != '-' || line[7] != '-')
		throw BitcoinExchange::ExceptionInput(line);
	for (size_t i = 0; i < 10; i++)
	{
		if (i == 4 || i == 7)
			continue ;
		else if (!isdigit(line[i]))
			throw BitcoinExchange::ExceptionDate(line.substr(0, 10));
	}
	year = std::atoi(line.substr(0, 4).c_str());
	if (year < 2009 || year > 2025)
		throw BitcoinExchange::ExceptionDate(line.substr(0, 10));
	month = std::atoi(line.substr(5, 2).c_str());
	if (month < 1 || month > 12)
		throw BitcoinExchange::ExceptionDate(line.substr(0, 10));

	day = std::atoi(line.substr(8, 2).c_str());
	bool isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
	if (isLeapYear)
		daysInMonth[1] = 29;
	if (day < 0 || day > daysInMonth[month - 1])
		throw BitcoinExchange::ExceptionDate(line.substr(0, 10));

	if (year == 2009 && month == 1 && day == 1)
		throw BitcoinExchange::ExceptionDate(line.substr(0, 10));

	if (line[10] != ' ' || line[11] != '|' || line[12] != ' ')
		throw BitcoinExchange::ExceptionInput(line);
	date.year = year;
	date.month = month;
	date.day = day;
}

float	parse_value(std::string line)
{
	float value;
	std::stringstream ss(line);
	ss >> std::fixed >> std::setprecision(2) >> value;
	if(line.size() > 4 || value > 1000)
		throw BitcoinExchange::ExceptionIntMax();
	else if (!ss.eof())
		throw BitcoinExchange::ExceptionNotaNumber();
	else if (value < 0)
		throw BitcoinExchange::ExceptionNegative();
	return (value);
}

void	print_message(t_date date, float value, float coeff)
{
	std::cout << date.year << '-';
	if (date.month < 10)
		std::cout << '0';
	std::cout << date.month << '-';
	if (date.day < 10)
		std::cout << '0';
	std::cout << date.day << " => " << value << " = " << coeff * value << std::endl;
}