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

void	swap(Vect::iterator it, size_t level)
{
	for (size_t k = 0; k < level; k++)
	{
		//std::cout << "On swap " << *(it + k) << " et " << *(it + k + level) << std::endl;
		std::iter_swap(it + k, it + k + level);
	}
}

void	sorting_pair(Vect &pairs, size_t level)
{
	// nl;
	//print("Level: " << level);
	// for (Vect::iterator it = pairs.begin(); it < pairs.end(); it++)
	// 	std::cout << *it << ' ';
	// nl;
	for (Vect::iterator it = pairs.begin(); it <= pairs.end() - (level * 2); it += level * 2)
	{
		if (*(it + level - 1) > *(it + (level * 2) - 1))
			swap(it, level);
	}

	// for (Vect::iterator it = pairs.begin(); it < pairs.end(); it++)
	// 	std::cout << *it << ' ';
	// nl;

	if (level * 4 < pairs.size())
		sorting_pair(pairs, level * 2);

	sorting(pairs, level);
}

Vect::iterator	binary_search(int target, Vect &main, Vect &old_main, size_t level, unsigned int nb_jacob, bool odd)
{
	Vect::iterator left = main.begin() + level - 1;
	Vect::iterator right = old_main.begin() + level - 1 + ((nb_jacob - 1) * level);

	if (odd)
		right = main.end() - 1 - (main.size() % level);
	else
	{
		right += level;
		right = std::find(main.begin(), main.end(), *right);
		right -= level;
	}
	
	
	Vect::iterator mid;
	// print("Left: " << *left << " ");
	// print("Right: " << *right << " ");
	// print("Distance left-right: " << std::distance(left, right));


	//nl;
	while (left < right)
	{
		mid = left + (((right - left) / (2 * level)) * level);
		if ((std::distance(main.begin(), mid) % level) != (level - 1)) 
			mid += (level - 1 - (std::distance(main.begin(), mid) % level));
		// print("Mid : (" << mid->first << " : " << mid->second << ")");
		// print("Mid: " << std::distance(main.begin(), mid));
		// print("mid modulo level:" << std::distance(main.begin(), mid) % level);
		//print("Mid: " << *mid);
		if (*mid < target)
		{
			left = mid + level;
			//print("Left devient: " << *left);
		}
		else
		{
			right = mid;
			//print("Right devient: " << *right);
		}
	}

	if (*left > target && left - level > main.begin())
		left -= level;
	//nl;

	return left;
}

void	insertion(Vect &main, Vect::iterator pos, Vect::iterator element, size_t level)
{
	// if (*pos > *element)
	// 	print("On veut inserer "  << *element << " a gauche de: " << *pos);
	// else
	// 	print("On veut inserer "  << *element << " a droite de: "  << *pos);
	// nl;

	if (*pos > *element && level > 1)
		main.insert(main.begin(), element - level + 1, element + 1);
	else if (*pos > *element && pos != main.begin())
		main.insert(pos, element - level + 1, element + 1);
	else if (*pos > *element)
		main.insert(main.begin(), element - level + 1, element + 1);
	else
	{
		if (pos < main.end())
			pos++;
		main.insert(pos, element - level + 1, element + 1);
	}

	// std::cout << "Main apres insertion: ";
	// for (Vect::iterator it = main.begin(); it < main.end(); it++)
	// 	std::cout << *it << ' ';
	// nl;
}


void	sorting(Vect &pairs, size_t level)
{

	//print("On appelle insertion au level:" << level);
	Vect	pend;
	Vect	odd;
	build_pend(pairs, pend, odd, level);
	Vect	old_main = pairs;

	if (pend.empty())
		return ;

	// nl;
	// print("Level: " << level);
	// std::cout << "Pend: ";
	// for (Vect::iterator it = pend.begin(); it < pend.end(); it++)
	// 	std::cout << *it << ' ';
	// if (!odd.empty())
	// {
	// 	std::cout << " | Odd: ";
	// 	for (Vect::iterator it = odd.begin(); it < odd.end(); it++)
	// 		std::cout << *it << ' ';
	// }
	// nl;

	// nl;
	// std::cout << "Main: ";
	// for (Vect::iterator it = pairs.begin(); it < pairs.end(); it++)
	// 	std::cout << *it << ' ';
	// nl;


	unsigned int	Jacob[2] = {1, 3};
	unsigned int	n;
	Vect::iterator pos;

	while (Jacob[0] <= pend.size() / level)
	{
		//print(Jacob[0]);
		Vect::iterator b = pend.begin() + level - 1;
		n = 2;
		while (n != Jacob[1] && b + level < pend.end())
		{
			b += level;
			n++;
		}
		while (n > Jacob[0])
		{
			//print("Binary search de: " << *b << " pour element b" << n);
			pos = binary_search(*b, pairs, old_main, level, n, false);
			insertion(pairs, pos, b, level);
			b -= level;
			n--;
		}
		//nl;
		n = Jacob[1];
		Jacob[1] = (Jacob[0] * 2) + Jacob[1];
		Jacob[0] = n;
	}
	if (odd.size() >= level)
	{
		//print("Binary search de: " << odd.back() << " pour element odd nb jacob: " << n);
		pos = binary_search(odd.back(), pairs, old_main, level, n, true);
		insertion(pairs, pos, odd.end() - 1, level);
	}
	else if (!odd.empty())
	{
		for (Vect::iterator it = odd.begin(); it < odd.end(); it++)
			pairs.push_back(*it);
	}
}


void	build_pend(Vect &pairs, Vect &pend, Vect &odd, size_t level)
{

	if (pairs.size() < level * 4)
		return ;

	for (Vect::iterator it = pairs.begin() + (2 * level); it < pairs.end(); it += level)
	{
		Vect::iterator k = it;
		if (it + (level * 2) >= pairs.end())
		{
			while (it < k + level && it < pairs.end())
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
	for (Vect::iterator it = pend.begin(); it < pend.end(); it++)
	{
		for (Vect::iterator k = pairs.begin(); k < pairs.end(); k++)
		{
			if (*k == *it)
			{
				pairs.erase(k);
				break ;
			}
		}
	}
	if (!odd.empty())
	{
		for (Vect::iterator it = odd.begin(); it < odd.size() + odd.begin(); it++)
		{
			for (Vect::iterator k = pairs.begin(); k < pairs.end(); k++)
			{
				if (*k == *it)
				{
					pairs.erase(k);
					break ;
				}
			}
		}
	}
	return ;
}


/// Meme chose avec Deque ///

void	swap_dq(Deque::iterator it, size_t level)
{
	for (size_t k = 0; k < level; k++)
	{
		//std::cout << "On swap " << *(it + k) << " et " << *(it + k + level) << std::endl;
		std::iter_swap(it + k, it + k + level);
	}
}

void	sorting_pair_dq(Deque &pairs, size_t level)
{
	// nl;
	//print("Level: " << level);
	// for (Deque::iterator it = pairs.begin(); it < pairs.end(); it++)
	// 	std::cout << *it << ' ';
	// nl;
	for (Deque::iterator it = pairs.begin(); it <= pairs.end() - (level * 2); it += level * 2)
	{
		if (*(it + level - 1) > *(it + (level * 2) - 1))
			swap_dq(it, level);
	}

	// for (Deque::iterator it = pairs.begin(); it < pairs.end(); it++)
	// 	std::cout << *it << ' ';
	// nl;

	if (level * 4 < pairs.size())
		sorting_pair_dq(pairs, level * 2);

	sorting_dq(pairs, level);
}

Deque::iterator	binary_search_dq(int target, Deque &main, Deque &old_main, size_t level, unsigned int nb_jacob, bool odd)
{
	Deque::iterator left = main.begin() + level - 1;
	Deque::iterator right = old_main.begin() + level - 1 + ((nb_jacob - 1) * level);

	if (odd)
		right = main.end() - 1 - (main.size() % level);
	else
	{
		right += level;
		right = std::find(main.begin(), main.end(), *right);
		right -= level;
	}
	
	
	Deque::iterator mid;
	// print("Left: " << *left << " ");
	// print("Right: " << *right << " ");
	// print("Distance left-right: " << std::distance(left, right));


	//nl;
	while (left < right)
	{
		mid = left + (((right - left) / (2 * level)) * level);
		if ((std::distance(main.begin(), mid) % level) != (level - 1)) 
			mid += (level - 1 - (std::distance(main.begin(), mid) % level));
		// print("Mid : (" << mid->first << " : " << mid->second << ")");
		// print("Mid: " << std::distance(main.begin(), mid));
		// print("mid modulo level:" << std::distance(main.begin(), mid) % level);
		//print("Mid: " << *mid);
		if (*mid < target)
		{
			left = mid + level;
			//print("Left devient: " << *left);
		}
		else
		{
			right = mid;
			//print("Right devient: " << *right);
		}
	}

	if (*left > target && left - level > main.begin())
		left -= level;
	//nl;

	return left;
}

void	insertion_dq(Deque &main, Deque::iterator pos, Deque::iterator element, size_t level)
{

	if (*pos > *element && level > 1)
		main.insert(main.begin(), element - level + 1, element + 1);
	else if (*pos > *element && pos != main.begin())
		main.insert(pos, element - level + 1, element + 1);
	else if (*pos > *element)
		main.insert(main.begin(), element - level + 1, element + 1);
	else
	{
		if (pos < main.end())
			pos++;
		// if (std::distance(main.begin(), element) < static_cast<int>(level) - 1)
		// 	return ;
		main.insert(pos, element - level + 1, element + 1);
	}

	// std::cout << "Main apres insertion: ";
	// for (Deque::iterator it = main.begin(); it < main.end(); it++)
	// 	std::cout << *it << ' ';
	// nl;

}


void	sorting_dq(Deque &pairs, size_t level)
{

	//print("On appelle insertion au level:" << level);
	Deque	pend;
	Deque	odd;
	build_pend_dq(pairs, pend, odd, level);
	Deque	old_main = pairs;

	if (pend.empty())
		return ;

	// nl;
	// print("Level: " << level);
	// std::cout << "Pend: ";
	// for (Deque::iterator it = pend.begin(); it < pend.end(); it++)
	// 	std::cout << *it << ' ';
	// if (!odd.empty())
	// {
	// 	std::cout << " | Odd: ";
	// 	for (Deque::iterator it = odd.begin(); it < odd.end(); it++)
	// 		std::cout << *it << ' ';
	// }
	// nl;

	// nl;
	// std::cout << "Main: ";
	// for (Deque::iterator it = pairs.begin(); it < pairs.end(); it++)
	// 	std::cout << *it << ' ';
	// nl;


	unsigned int	Jacob[2] = {1, 3};
	unsigned int	n;
	Deque::iterator pos;

	while (Jacob[0] <= pend.size() / level)
	{
		//print(Jacob[0]);
		Deque::iterator b = pend.begin() + level - 1;
		n = 2;
		while (n != Jacob[1] && b + level < pend.end())
		{
			b += level;
			n++;
		}
		while (n > Jacob[0])
		{
			//print("Binary search de: " << *b << " pour element b" << n);
			pos = binary_search_dq(*b, pairs, old_main, level, n, false);
			insertion_dq(pairs, pos, b, level);
			b -= level;
			n--;
		}
		//nl;
		n = Jacob[1];
		Jacob[1] = (Jacob[0] * 2) + Jacob[1];
		Jacob[0] = n;
	}
	if (odd.size() >= level)
	{
		//print("Binary search de: " << odd.back() << " pour element odd nb jacob: " << n);
		pos = binary_search_dq(odd.back(), pairs, old_main, level, n, true);
		insertion_dq(pairs, pos, odd.end() - 1, level);
	}
	else if (!odd.empty())
	{
		for (Deque::iterator it = odd.begin(); it < odd.end(); it++)
			pairs.push_back(*it);
	}
}


void	build_pend_dq(Deque &pairs, Deque &pend, Deque &odd, size_t level)
{

	if (pairs.size() < level * 4)
		return ;

	for (Deque::iterator it = pairs.begin() + (2 * level); it < pairs.end(); it += level)
	{
		Deque::iterator k = it;
		if (it + (level * 2) >= pairs.end())
		{
			while (it < k + level && it < pairs.end())
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
	for (Deque::iterator it = pend.begin(); it < pend.end(); it++)
	{
		for (Deque::iterator k = pairs.begin(); k < pairs.end(); k++)
		{
			if (*k == *it)
			{
				pairs.erase(k);
				break ;
			}
		}
	}
	if (!odd.empty())
	{
		for (Deque::iterator it = odd.begin(); it < odd.size() + odd.begin(); it++)
		{
			for (Deque::iterator k = pairs.begin(); k < pairs.end(); k++)
			{
				if (*k == *it)
				{
					pairs.erase(k);
					break ;
				}
			}
		}
	}
	return ;
}
