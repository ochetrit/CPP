/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochetrit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:43:29 by ochetrit          #+#    #+#             */
/*   Updated: 2025/02/05 16:43:29 by ochetrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <stack>

#define print(x) std::cout << x << std::endl
#define perr(x) std::cerr << x << std::endl
#define nl std::cout << std::endl

class RPN
{
	private :

	std::stack<int> stack;
	unsigned int	op;

	public :
	
	RPN();
	RPN(const RPN &other);
	
	~RPN();

	void	manipulatemystack(char c);
	void	checkmystack();

	RPN	&operator=(const RPN &other);

	class ExceptionFormat: public std::exception
	{
		public :

		virtual const char	*what() const throw();
	};

	class ExceptionNumbers: public std::exception
	{
		public :

		virtual const char	*what() const throw();
	};

	class ExceptionOperators: public std::exception
	{
		public :

		virtual const char	*what() const throw();
	};

	class ExceptionDiv: public std::exception
	{
		public :

		virtual const char	*what() const throw();
	};

};