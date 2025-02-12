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

	sorting(pairs, level);
}

Pair::iterator	binary_search(int target, Pair &main, Pair &old_main, size_t level, unsigned int nb_jacob, bool odd)
{
	Pair::iterator left = main.begin() + level - 1;
	Pair::iterator right = old_main.begin() + level - 1 + ((nb_jacob - 1) * level);

	if (odd)
		right = main.begin() + level - 1 + ((nb_jacob - 1) * level);
	else
	{
		right += level;
		right = std::find(main.begin(), main.end(), *right);
		right -= level;
	}
	
	
	Pair::iterator mid;
	print("Left : (" << left->first << " : " << left->second << ")");
	print("Right : (" << right->first << " : " << right->second << ")");
	print("Distance left-right: " << std::distance(left, right));


	nl;
	while (left < right)
	{
		mid = left + (((right - left) / (2 * level)) * level);
		if ((std::distance(main.begin(), mid) % level) != (level - 1)) 
			mid += (level - 1 - (std::distance(main.begin(), mid) % level));
		// print("Mid : (" << mid->first << " : " << mid->second << ")");
		// print("Mid: " << std::distance(main.begin(), mid));
		// print("mid modulo level:" << std::distance(main.begin(), mid) % level);
		print("Mid : (" << mid->first << " : " << mid->second << ")");
		if (mid->second < target)
		{
			left = mid + level;
			print("Left devient: (" << left->first << " : " << left->second << ")");
		}
		else
		{
			right = mid;
			print("Right devient: (" << right->first << " : " << right->second << ")");
		}
	}

	if (left->second > target && left - level > main.begin())
		left -= level;
	nl;

	return left;
}

void	insertion(Pair &main, Pair::iterator pos, Pair::iterator element, size_t level)
{
	if (pos->second > element->second)
		print("On veut inserer ("  << element->first << " : " << element->second << ")"<< " a gauche de: ("  << pos->first << " : " << pos->second << ")");
	else
		print("On veut inserer ("  << element->first << " : " << element->second << ")"<< " a droite de: ("  << pos->first << " : " << pos->second << ")");
	nl;

	if (pos->second > element->second)
		main.insert(main.begin(), element - level + 1, element + 1);
	else
	{
		if (pos < main.end())
			pos++;
		main.insert(pos, element - level + 1, element + 1);
	}

	std::cout << "Main apres insertion: ";
	for (Pair::iterator it = main.begin(); it < main.end(); it++)
		std::cout << "(" << it->first << ' ' << it->second << ")";
	nl;
}


void	sorting(Pair &pairs, size_t level)
{

	print("On appelle insertion au level:" << level);
	Pair	pend;
	Pair	odd;
	build_pend(pairs, pend, odd, level);
	Pair	old_main = pairs;

	if (pend.empty())
		return ;

	nl;
	print("Level: " << level);
	std::cout << "Pend: ";
	for (Pair::iterator it = pend.begin(); it < pend.end(); it++)
		std::cout << "(" << it->first << ' ' << it->second << ")";
	std::cout << " | Odd: ";
	for (Pair::iterator it = odd.begin(); it < odd.end(); it++)
		std::cout << "(" << it->first << ' ' << it->second << ")";
	nl;

	nl;
	std::cout << "Main: ";
	for (Pair::iterator it = pairs.begin(); it < pairs.end(); it++)
		std::cout << "(" << it->first << ' ' << it->second << ")";
	nl;


	unsigned int	Jacob[2] = {1, 3};
	unsigned int	n;
	Pair::iterator pos;

	while (Jacob[0] <= pend.size() / level)
	{
		print(Jacob[0]);
		Pair::iterator b = pend.begin() + level - 1;
		n = 2;
		while (n != Jacob[1] && b + level < pend.end())
		{
			b += level;
			n++;
		}
		while (n > Jacob[0])
		{
			print("Binary search de la paire: (" << b->first << ':' << b->second << ") pour element b" << n);
			pos = binary_search(b->second, pairs, old_main, level, n, false);
			insertion(pairs, pos, b, level);
			b -= level;
			n--;
		}
		nl;
		n = Jacob[1];
		Jacob[1] = (Jacob[0] * 2) + Jacob[1];
		Jacob[0] = n;
	}
	print("Binary search de la paire: (" << odd.back().first << ':' << odd.back().second << ") pour element odd");
	pos = binary_search(odd.back().second, pairs, old_main, level, n, true);
	insertion(pairs, pos, odd.end() - 1, level);
}


void	build_pend(Pair &pairs, Pair &pend, Pair &odd, size_t level)
{

	if (pairs.size() < level * 4)
		return ;

	for (Pair::iterator it = pairs.begin() + (2 * level); it < pairs.end(); it += level)
	{
		Pair::iterator k = it;
		if (it + (level * 2) >= pairs.end())
		{
			while (it < k + level)
			{
				odd.push_back(*it);
				it++;
			}
			break ;
		}
		while (it < k + level)
		{
			pend.push_back(*it);
			it++;
		}
	}
	for (Pair::iterator it = pend.begin(); it < pend.end(); it++)
	{
		for (Pair::iterator k = pairs.begin(); k < pairs.end(); k++)
		{
			if (k->second == it->second)
			{
				pairs.erase(k);
				break ;
			}
		}
	}
	for (Pair::iterator it = odd.begin(); it < odd.end(); it++)
	{
		for (Pair::iterator k = pairs.begin(); k < pairs.end(); k++)
		{
			if (k->second == it->second)
			{
				pairs.erase(k);
				break ;
			}
		}
	}
	return ;
}