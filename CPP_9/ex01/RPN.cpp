/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochetrit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:43:32 by ochetrit          #+#    #+#             */
/*   Updated: 2025/02/05 16:43:33 by ochetrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{
	//print("Default constructor has been called.");
}

RPN::RPN(const RPN &other)
{
	*this = other;
}

RPN::~RPN()
{
	//print("Destruction of RPN");
}

RPN	&RPN::operator=(const RPN &other)
{
	if (this != &other)
	{
		stack = other.stack;
		op = other.op;
	}
	return (*this);
}

void	RPN::manipulatemystack(char c)
{
	int tmp = 0;

	if (c >= '0' && c <= '9')
		stack.push(c - '0');
	else if (c == '+')
	{
		if (stack.size() < 2)
			throw ExceptionNumbers();
		tmp = stack.top();
		stack.pop();
		tmp += stack.top();
		stack.pop();
		stack.push(tmp);
	}
	else if (c == '-')
	{
		if (stack.size() < 2)
			throw ExceptionNumbers();
		tmp = stack.top();
		stack.pop();
		tmp = stack.top() - tmp;
		stack.pop();
		stack.push(tmp);
	}
	else if (c == '*')
	{
		if (stack.size() < 2)
			throw ExceptionNumbers();
		tmp = stack.top();
		stack.pop();
		tmp *= stack.top();
		stack.pop();
		stack.push(tmp);
	}
	else if (c == '/')
	{
		if (stack.size() < 2)
			throw ExceptionNumbers();
		tmp = stack.top();
		stack.pop();
		if (tmp == 0)
			throw ExceptionDiv();
		tmp = stack.top() / tmp;
		stack.pop();
		stack.push(tmp);
	}
}

void	RPN::checkmystack()
{
	if (stack.size() != 1)
		throw ExceptionOperators();
	print(stack.top());
}


const char	*RPN::ExceptionFormat::what() const throw()
{
	return ("Error, I need only numbers or operator!");
}

const char	*RPN::ExceptionNumbers::what() const throw()
{
	return ("Error, I don't have enough numbers to do my operation");
}

const char	*RPN::ExceptionOperators::what() const throw()
{
	return ("Error, my stack has more than one numbers, I need more operators");
}

const char	*RPN::ExceptionDiv::what() const throw()
{
	return ("Error, you CAN'T divide a number with 0 !");
}