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
#include <string>
#include <cstdlib>

#define nl std::cout << std::endl

template <typename T>

void    swap(T *a, T *b)
{
    T   tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

template <typename T>

T       min(const T a, const T b)
{
    return (a < b ? a : b);
}

template <typename T>

T       max(const T a, const T b)
{
    return (a > b ? a : b);
}