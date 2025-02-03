/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochetrit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 14:22:22 by ochetrit          #+#    #+#             */
/*   Updated: 2025/02/02 14:22:22 by ochetrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

template <typename T>
void	iter(T *array, size_t length, void	f(T const &ref))
{
	for (size_t i = 0; i < length; i++)
		f(array[i]);
}

template <typename T>
void	display(T &obj)
{
	std::cout << obj << std::endl;
}

