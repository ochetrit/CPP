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
		else if ((it + level - 1)->second > (it + (level * 2) - 1)->second)
			swap(it, level);
	}

	/* for (Pair::iterator it = pairs.begin(); it < pairs.end(); it++)
		std::cout << "(" << it->first << ' ' << it->second << ")";
	nl; */

	if (level * 4 < pairs.size())
		sorting_pair(pairs, level * 2);

	insertion(pairs, level);
}


void	insertion(Pair pairs, size_t level)
{
	print("On appelle insertion au level:" << level);
	int	Jacob[2] = {1, 3};

	if (pairs.size() < level * 4)
		return ;

	int tmp;
	Pair::iterator odd;

	while (Jacob[0] * level < pairs.size())
	{
		tmp = Jacob[1];
		while (tmp * level * 2 > pairs.size())
			tmp--;
		while (tmp > Jacob[0])
		{
			print("Nb de Jacob: " << tmp);
			tmp--;
		}
		tmp = Jacob[0];
		Jacob[0] = Jacob[1];
		Jacob[1] = Jacob[1] + (tmp * 2);
		print("Jacob = (" << Jacob[0] << ':' << Jacob[1] << ')');
	}
}