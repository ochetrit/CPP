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

int	main(int ac, char **av)
{
	if (ac < 3)
		return perr("I need at least two arguments in order to sort them"), 1;
	
	Vect	elmnt;

	if (!parse_args(++av, ac, elmnt))
		return 2;
	std::cout << "Before: ";
	for (Vect::iterator it = elmnt.begin(); it < elmnt.end(); it++)
	{
		std::cout << *it;
		if (it + 1 != elmnt.end())
			std::cout << ' ';
		else
			nl;
	}

	Pair	pairs;
	fill_pairs(pairs, elmnt);

	for (Pair::iterator it = pairs.begin(); it < pairs.end(); it++)
		std::cout << "(" << it->first << ' ' << it->second << ")";
	nl;

/* 	for (size_t level = 1; level * 4 < pairs.size(); level *= 2)
		sorting_pair(pairs, level); */	/// iterative version

	sorting_pair(pairs, 1);

	nl;
	for (Pair::iterator it = pairs.begin(); it < pairs.end(); it++)
		std::cout << "(" << it->first << ' ' << it->second << ")";

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

void	fill_pairs(Pair &pairs, Vect elmnt)
{
	for (Vect::iterator it = elmnt.begin(); it < elmnt.end(); it += 2)
	{
		if (it + 1 == elmnt.end())
		{
			pairs.push_back(std::make_pair(*it, -1));
			break ;
		}
		else if (*it < *(it + 1))
			pairs.push_back(std::make_pair(*it, *(it + 1)));
		else
			pairs.push_back(std::make_pair(*(it + 1), *it));
	}
}