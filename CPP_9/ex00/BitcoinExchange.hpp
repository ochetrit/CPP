/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochetrit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:37:07 by ochetrit          #+#    #+#             */
/*   Updated: 2025/02/04 17:37:07 by ochetrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <map>
#include <iomanip>
#include <sstream>
#include <limits>
#include <ios>

#define print(x) std::cout << x << std::endl
#define nl std::cout << std::endl

#define catch(x) catch(const x &e)\
				{										\
					std::cerr << e.what() << std::endl;\
				}



typedef struct s_date
{
	unsigned int year;
	unsigned int month;
	unsigned int day;

	bool	operator<(const s_date &other) const;
}	t_date;

class BitcoinExchange
{
	private:
	std::map<t_date, float>	_map;
	std::ifstream	_fd;
	std::string		_filename;

	public:
	BitcoinExchange();
	BitcoinExchange(std::string filename);
	BitcoinExchange(const BitcoinExchange &other);

	BitcoinExchange &operator=(const BitcoinExchange &other);

	~BitcoinExchange();

	void	fill_map();
	void	print_map();
	float	coeff(t_date date);

	class	ExceptionDate: public std::exception
	{
		private :

		std::string msg;

		public :

		ExceptionDate(const std::string date);
		virtual ~ExceptionDate() throw();
		virtual const char  *what() const throw();
	};

	class	ExceptionInput: public std::exception
	{
		private :

		std::string msg;

		public :

		ExceptionInput(const std::string date);
		virtual ~ExceptionInput() throw();
		virtual const char  *what() const throw();
	};

	class	ExceptionValue: public std::exception
	{
		public :

	virtual const char  *what() const throw();
	};

	class	ExceptionOpen: public std::exception
	{
		public :

		virtual const char  *what() const throw();
	};

	class	ExceptionIntMax: public std::exception
	{
		public :

		virtual const char  *what() const throw();
	};

	class	ExceptionNegative: public std::exception
	{
		public :

		virtual const char  *what() const throw();
	};

	class	ExceptionNotaNumber: public std::exception
	{
		public :

		virtual const char  *what() const throw();
	};

};

