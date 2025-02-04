/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochetrit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 14:01:44 by ochetrit          #+#    #+#             */
/*   Updated: 2025/02/04 14:01:44 by ochetrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stack>
#include <cstdlib>

#define print(x) std::cout << x << std::endl
#define nl std::cout << std::endl

template <typename T>
class MutantStack : public std::stack<T>
{
    public :

    MutantStack(): std::stack<T>(){}

    MutantStack(const MutantStack &other):std::stack<T>(other){}
    ~MutantStack()
    {
        print("Desctructor has been called.");
    }

    MutantStack &operator=(const MutantStack &other)
    {
        if (this != &other)
            std::stack<T>::operator=(other);
        return (*this);
    }

    typedef typename std::stack<T>::container_type::iterator iterator;
    iterator begin()
    {
        return (std::stack<T>::c.begin());
    }

    iterator end()
    {
        return (std::stack<T>::c.end());
    }

};