/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochetrit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:49:57 by ochetrit          #+#    #+#             */
/*   Updated: 2025/02/03 13:49:59 by ochetrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <algorithm>

#define print(x) std::cout << x << std::endl
#define nl std::cout << std::endl


class NotFoundException: public std::exception
{
    public :

    virtual const char  *what() const throw()
    {
        return ("Not found the target number in this vector");
    }
};


template <typename T>

typename T::iterator   easyfind(T v, int nb)
{
    typename T::iterator   it;
    if ((it = std::find(v.begin(), v.end(), nb)) == v.end())
        throw (NotFoundException());
    return it;
}
