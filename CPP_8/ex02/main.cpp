/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochetrit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 14:01:28 by ochetrit          #+#    #+#             */
/*   Updated: 2025/02/04 14:01:28 by ochetrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int	main()
{
	MutantStack<int> arr1;

    std::string index;

    print("Let's build a vector, give me one int:");

    if (!getline(std::cin, index))
        return (1);
    int vect = atoi(index.c_str());

    for (size_t i = 0; i < 10; i++)
    {
        arr1.push((i * vect) % 100);
    }
    nl;
    print("This is our vector");
    for (MutantStack<int>::iterator it = arr1.begin(); it < arr1.end(); it++)
    {
        print(*it);
    }

    nl;
    print("We still have stack proprieties:");
    nl;

    print("Last element and size before pop: " << arr1.top() << " | " << arr1.size());
    arr1.pop();
    print("Last element and size before pop: " << arr1.top() << " | " << arr1.size());
}
