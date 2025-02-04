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
	Span arr1(100);

    std::string index;

    print("Let's build a vector, give me one int:");

    if (!getline(std::cin, index))
        return (1);
    int vect = atoi(index.c_str());

    nl;
    print("This is our vector");
    try
    {
        for (size_t i = 0; i < 100; i++)
        {
            arr1.addNumber((i * vect) % 1000);
            print(arr1.getvector().back());
        }
    }
    catch(const Span::ExceptionFull &e)
    {
        std::cerr << e.what() << '\n';
    }

    nl;

	Span	arr2(arr1);

    nl;

    try
    {
        print(arr2.longestSpan());
        print(arr2.shortestSpan());
    }
    catch(const Span::ExceptionEmpty &e)
    {
        std::cerr << e.what() << '\n';
    }

}