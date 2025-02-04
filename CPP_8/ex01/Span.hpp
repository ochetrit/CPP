/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochetrit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:49:51 by ochetrit          #+#    #+#             */
/*   Updated: 2025/02/03 13:49:51 by ochetrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define print(x) std::cout << x << std::endl
#define nl std::cout << std::endl

class Span
{
	private :

	unsigned int _size;
	std::vector<int>	_array;
	Span();

	public :

	Span(unsigned int N);
	Span(const Span &other);

	Span	&operator=(const Span &other);

	std::vector<int>	getvector();
	void	addNumber(int n);
	int		longestSpan();
	int		shortestSpan();

	class	ExceptionFull: public std::exception
	{
		public :
		
		virtual const char	*what() const throw();
	};

	class	ExceptionEmpty: public std::exception
	{
		public:

		virtual const char	*what() const throw();
	};
};