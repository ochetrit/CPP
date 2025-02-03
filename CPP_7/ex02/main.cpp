/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochetrit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 10:20:45 by ochetrit          #+#    #+#             */
/*   Updated: 2025/02/03 10:20:46 by ochetrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main()
{
    Array<int>  first;
    unsigned int len;

    try
    {
        len = first.size();
        print("first size: " << len);
        print(first[0]);
    }
    catch (const Array<int>::IndexError &e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::string index;

    nl;

    print("Let's try with an array of ints, give me one int:");

    if (!getline(std::cin, index))
        return (1);
    int vect = atoi(index.c_str());

    Array<int> second(10);
	for (size_t i = 0; i < 10; i++)
	{
		second[i] = ((i * vect) % 100);
		print(second[i]);
	}

	nl;
	print("Let s copy this vector on a third one :");

	Array<int>	third(second);

	for (size_t i = 0; i < 10; i++)
	{
		third[i] = ((i * vect) % 100);
		print(third[i]);
	}

	print("Let's modify one element of my second array and check that it doesn't affect the third one");
	print("Give me one index: (between 0 and 9 or it'll throw an exception)");
	if (!getline(std::cin, index))
        return (1);
    unsigned int n = atoi(index.c_str());

	nl;
	print("Give me the new value");
	if (!getline(std::cin, index))
        return (1);
    int value = atoi(index.c_str());

	try
	{
		third[n] = value;
		print("Value of array nb 2: " << second[n]);
		print("Value of array nb 3: " << third[n]);
	}
	catch (const Array<int>::IndexError &e)
	{
		std::cerr << e.what() << std::endl;
	}
}