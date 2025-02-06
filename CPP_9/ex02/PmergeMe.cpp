/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochetrit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:45:42 by ochetrit          #+#    #+#             */
/*   Updated: 2025/02/06 12:45:43 by ochetrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void	swap(Pair::iterator it, size_t level)
{
	for (size_t k = 0; k < level; k++)
	{
		std::cout << "On swap les paires (" << (it + k)->first << ' ' << (it + k)->second << ") et ("<< (it + k + level)->first << ' ' << (it + k + level)->second << ")" << std::endl;
		std::iter_swap(it + k, it + k + level);
	}
}

void	sorting_pair(Pair &pairs, size_t level)
{
	nl;
	print("Level: " << level);
	for (Pair::iterator it = pairs.begin(); it < pairs.end() - (level * 2); it += level * 2)
	{
		if (it > pairs.end() - (level * 2))
			break ;
		else if ((it + level - 1)->second > (it + (level * 2) - 1)->second) /// sur de moi sur celle la
			swap(it, level);
	}

	for (Pair::iterator it = pairs.begin(); it < pairs.end(); it++)
		std::cout << "(" << it->first << ' ' << it->second << ")";
	nl;

	if (level * 4 < pairs.size())
		sorting_pair(pairs, level * 2);
}