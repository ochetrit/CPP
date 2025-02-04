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

#include "Span.hpp"

Span::Span(){}

Span::Span(unsigned int size):_size(size)
{
	_array.reserve(_size);
	print("Constructor with a size of " << _size);
}

Span::Span(const Span &other)
{
	print("Copy constructor has been called");
	*this = other;
}

Span	&Span::operator=(const Span &other)
{
	if (this != &other)
	{
		_size = other._size;
		_array.reserve(other._array.capacity());
		_array = other._array;
	}
	return *this;
}

void	Span::addNumber(int n)
{
	if (_array.size() >= _size)
		throw ExceptionFull();
	_array.push_back(n);
}

int	Span::longestSpan()
{
	if (_array.size() <= 1)
		throw(ExceptionEmpty());
	return (*std::max_element(_array.begin(), _array.end()) - *std::min_element(_array.begin(), _array.end()));
}

int	Span::shortestSpan()
{

	if (_array.size() <= 1)
		throw(ExceptionEmpty());

	std::vector<int>	v(_array);

	std::sort(v.begin(), v.end());
	int	Dist = v[1] - v[0];
	for (std::vector<int>::iterator it = v.begin(); it < v.end() - 1; it++)
	{
		if (*(it + 1) - *it < Dist)
			Dist = *(it + 1) - *it;
	}
	return (Dist);
}

std::vector<int>	Span::getvector()
{
	return _array;
}

const char	*Span::ExceptionFull::what() const throw()
{
	return ("The vector is full !");
}

const char	*Span::ExceptionEmpty::what() const throw()
{
	return ("Not enough elements to find a span...");
}