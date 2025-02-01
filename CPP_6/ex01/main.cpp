/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochetrit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:39:54 by ochetrit          #+#    #+#             */
/*   Updated: 2025/02/01 15:39:55 by ochetrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(int ac, char **av)
{
    std::string input;

    (void)av;
    if (ac != 1){
        print("Error 404"); return(404);
    }

    Data    *ptr = new (Data);
    print("I need a key for my Data");

    if (!std::getline(std::cin, input) || input.empty())
        print("okkk");
    ptr->key = std::atol(input.c_str());

    print("I need an info for my Data");

    if (!std::getline(std::cin, input) || input.empty())
        print("okkk");

    ptr->info = input;

    uintptr_t  raw = Serializer::serialize(ptr);
    ptr = Serializer::deserialize(raw);

    nl;
    print("key: " << ptr->key);
    print("info: " << ptr->info);

    delete ptr;

}