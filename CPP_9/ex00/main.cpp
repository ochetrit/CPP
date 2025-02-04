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


void	parse_file(std::ifstream fd);

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

	try
	{
		std::string filename("data.csv");
		BitcoinExchange	bct(filename.c_str());
		(void)av;
		bct.fill_map();
		std::ifstream fd(av[1]);
		if (!fd)
			throw BitcoinExchange::ExceptionOpen();
		parse_file(fd);
	}
	catch(const BitcoinExchange::ExceptionDate &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch(const BitcoinExchange::ExceptionValue &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch(const BitcoinExchange::ExceptionOpen &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}

void	parse_file(std::ifstream fd)
{
	std::string	line;

	while (getline(fd, line))
	{
		for (size_t i = 0; i < 4; i++)
		{
			if (!isdigit(line[i]))
				throw BitcoinExchange::ExceptionDate();
		}
		
	}
}