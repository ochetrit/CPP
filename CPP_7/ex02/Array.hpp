/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochetrit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 10:20:40 by ochetrit          #+#    #+#             */
/*   Updated: 2025/02/03 10:20:42 by ochetrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include <cstdlib>

template <typename T>
#define print(x) std::cout << x << std::endl
#define nl std::cout << std::endl

class Array
{
    private :

    unsigned int   len;
    T   *array;

    public :

    Array(): len(0)
    {
		print("Default constructor");
        array = new T[len];
    }

	Array(unsigned int n): len(n)
	{
		print("Construct an array of len: " << len);
		array = new T[len];
	}

	Array(const Array &other):len(other.len)
	{
		print("Copy constructor");
		array = NULL;
		*this = other;
	}

	~Array()
	{
		print("Destructor");
		if (array)
			delete [] array;
	}

	Array	&operator=(const Array &other)
	{
		if (this != &other)
		{
			len = other.len;
			if (array != NULL)
				delete array;
			array = new	T[len];
			for (unsigned int i = 0; i < len; i++)
				array[i] = other.array[i];
		}
		return (*this);
	}

	
	T	&operator[](unsigned int n)
	{
		if (n < len && array)
			return array[n];
		throw Array<T>::IndexError();
	}

	unsigned long	size()
	{
		return(len);
	}

	class IndexError: public std::exception
	{
		public:

		virtual const char	*what() const throw()
		{
			return ("Error: Wrong inndex");
		}
	};
};