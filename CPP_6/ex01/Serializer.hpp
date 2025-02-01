/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochetrit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:39:45 by ochetrit          #+#    #+#             */
/*   Updated: 2025/02/01 15:39:46 by ochetrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <cstdlib>
#include <stdint.h>

#define print(x) std::cout << x << std::endl;
#define nl std::cout << std::endl;

struct Data
{
    std::string info;
    size_t      key;
};

class Serializer
{
    private :
    Serializer();
    Serializer(const Serializer &other);

    public :
    ~Serializer();

    Serializer  &operator=(const Serializer &other);

    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);
};

