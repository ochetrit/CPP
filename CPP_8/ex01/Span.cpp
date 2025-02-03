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

Span::std::vector<int>	getvector()
{
	return _array;
}

const char	*Span::ExceptionFull::what() const throw()
{
	return ("The vector is full !");
}