/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochetrit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:45:13 by ochetrit          #+#    #+#             */
/*   Updated: 2025/02/06 12:45:13 by ochetrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

bool	is_sorted(Vect vect)
{
	for (Vect::iterator it = vect.begin(); it + 1 < vect.end(); it++)
	{
		if (*it > *(it + 1))
			return false;
	}

	std::cout << "After: ";
	for (Vect::iterator it = vect.begin(); it < vect.end(); it++)
	{
		std::cout << *it;
		if (it + 1 != vect.end())
			std::cout << ' ';
		else
			nl;
	}

	print("Time to process a range of " << vect.size() << " elements with std::vector :	" << 0 << " ms");
	print("Time to process a range of " << vect.size() << " elements with std::deque :	" << 0 << " ms");

	return true;
}

bool	is_sorted_dq(Deque deque)
{
	for (Deque::iterator it = deque.begin(); it + 1 < deque.end(); it++)
	{
		if (*it > *(it + 1))
			return false;
	}

	return true;
}




int	main(int ac, char **av)
{
	if (ac < 3)
		return perr("I need at least two arguments in order to sort them"), 1;
	
	Vect	elmnt;
	Deque	dq;

	if (!parse_args(++av, ac, elmnt))
		return 2;
	std::cout << "Before: ";
	for (Vect::iterator it = elmnt.begin(); it < elmnt.end(); it++)
	{
		std::cout << *it;
		dq.push_back(*it);
		if (it + 1 != elmnt.end())
			std::cout << ' ';
		else
			nl;
	}

	if (is_sorted(elmnt))
		return 0;
	size_t size = elmnt.size();

/* 	for (size_t level = 1; level * 4 < pairs.size(); level *= 2)
		sorting_pair(pairs, level); iterative version*/

	clock_t start, end;

	start = clock();

	sorting_pair(elmnt, 1);

	std::cout << "After:  ";
	for (Vect::iterator it = elmnt.begin(); it < elmnt.end(); it++)
	{
		std::cout << *it;
		if (it + 1 != elmnt.end())
			std::cout << ' ';
		else
			nl;
	}

	//Vect test = elmnt;

	//std::sort(test.begin(), test.end());
	end = clock();


	// print("Size de base: " << cpy.size() << " et size finale: " << elmnt.size());
	// if (elmnt == test)
	// 	print("Sort success !");

	nl;

	double time = 1000 *((static_cast<double>(end - start)) / CLOCKS_PER_SEC );
	if (time < 100)
		print("Time to process a range of " << size << " elements with std::vector :	" << time << " ms");
	else
		print("Time to process a range of " << size << " elements with std::vector :	" << time / 1000 << " s");

	start = clock();

	sorting_pair_dq(dq, 1);

	// if (is_sorted_dq(dq) && dq.size() == elmnt.size())
	// 	print("SUCCESS");

	end = clock();


	time = 1000 *((static_cast<double>(end - start)) / CLOCKS_PER_SEC );
	if (time < 100)
		print("Time to process a range of " << size << " elements with std::deque :	" << time << " ms");
	else
		print("Time to process a range of " << size << " elements with std::deque :	" << time / 1000 << " s");
	// nl;
	// std::cout << "Deque trie: ";
	// for (Deque::iterator it = dq.begin(); it != dq.end(); it++)
	// {
	// 	std::cout << *it << ' ';
	// }
	// nl;
}

bool	parse_args(char **av, int ac, Vect &elmnt)
{
	std::string	everychar = "0123456789+";
	long	nb;

	// We check that we only have int

	for (int i = 0; i < ac - 1; i++)
	{
		if (!*av[i])
			return perr("One arg is empty"), false;
		for (size_t j = 0; j < strlen(av[i]); j++)
		{
			if (everychar.find(av[i][j]) == std::string::npos)
				return perr(av[i] << " is not a valid arg"), false;
		}

		unsigned int pos = av[i][0] == '+';
		if (strlen(av[i]) > 10 + pos)
			return perr(av[i] << " will overflow, I need an int"), false;
		nb = std::strtol(av[i], NULL, 10);
		if (nb > std::numeric_limits<int>::max())
			return perr(av[i] << " will overflow, I need an int"), false;

		if (find(elmnt.begin(), elmnt.end(), nb) == elmnt.end())
			elmnt.push_back(nb);
	}
	return true;
}
