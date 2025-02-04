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

#include "easyfind.hpp"

int main()
{
    std::vector<int> v;

    std::string index;

    print("Let's build a vector, give me one int:");

    if (!getline(std::cin, index))
        return (1);
    int vect = atoi(index.c_str());

    nl;
    print("This is our vector");
	for (size_t i = 0; i < 10; i++)
	{
        v.push_back((i * vect) % 20);
        print(v.back());
    }

    nl;
    print("Give the element you re looking for:");
    if (!getline(std::cin, index))
        return (1);
    int nb = atoi(index.c_str());
    try
    {
        easyfind(v, nb);
    }
    catch(const NotFoundException &e)
    {
        std::cerr << e.what() << std::endl;
    }
    
}
