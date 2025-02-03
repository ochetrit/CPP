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

int	main()
{
	Span arr1(10);

    std::string index;

    print("Let's build a vector, give me one int:");

    if (!getline(std::cin, index))
        return (1);
    int vect = atoi(index.c_str());

    nl;
    print("This is our vector");
	for (size_t i = 0; i < 10; i++)
	{
        arr1.addNumber((i * vect) % 20);
        print(arr1.getvector().back());
    }

    nl;

	
	Span	arr2(arr1);
	print("This is our vector");
	for (size_t i = 0; i < 10; i++)
        print(arr2.getvector()[i]);
}