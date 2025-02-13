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



//// SAME ALGO BUT WITH LIST ////


void	swap_l(List::iterator it, size_t level)
{
	List::iterator it2(it);
	for (size_t k = 0; k < level; k++)
	{
		std::advance(it2, level);
		it++;
		it2++;
		//std::cout << "On swap " << *(it + k) << " et " << *(it + k + level) << std::endl;
		std::iter_swap(it, it2);
	}
}

void	sorting_pair_l(List &pairs, size_t level)
{
	nl;
	print("Level: " << level);

	List::iterator lim = pairs.end();
	std::advance(lim, (-2 * level) + 1);
	for (List::iterator it = pairs.begin(); it != lim; it = incr(pairs, it, level * 2))
	{
		if (it == pairs.end())
			break ;
		if (*incr(pairs, it, level - 1) > *incr(pairs, it, (level * 2) - 1))
			swap_l(it, level);
	}

	for (List::iterator it = pairs.begin(); it != pairs.end(); it++)
		std::cout << *it << ' ';
	nl;

	if (level * 4 < pairs.size())
		sorting_pair_l(pairs, level * 2);

	//sorting_l(pairs, level);
}

// List::iterator	binary_search_l(int target, List &main, List &old_main, size_t level, unsigned int nb_jacob, bool odd)
// {
// 	List::iterator left = main.begin() + level - 1;
// 	List::iterator right = old_main.begin() + level - 1 + ((nb_jacob - 1) * level);

// 	if (odd)
// 		right = main.end() - 1 - (main.size() % level);
// 	else
// 	{
// 		right += level;
// 		right = std::find(main.begin(), main.end(), *right);
// 		right -= level;
// 	}
	
	
// 	List::iterator mid;
// 	// print("Left: " << *left << " ");
// 	// print("Right: " << *right << " ");
// 	// print("Distance left-right: " << std::distance(left, right));


// 	//nl;
// 	while (left < right)
// 	{
// 		mid = left + (((right - left) / (2 * level)) * level);
// 		if ((std::distance(main.begin(), mid) % level) != (level - 1)) 
// 			mid += (level - 1 - (std::distance(main.begin(), mid) % level));
// 		// print("Mid : (" << mid->first << " : " << mid->second << ")");
// 		// print("Mid: " << std::distance(main.begin(), mid));
// 		// print("mid modulo level:" << std::distance(main.begin(), mid) % level);
// 		//print("Mid: " << *mid);
// 		if (*mid < target)
// 		{
// 			left = mid + level;
// 			//print("Left devient: " << *left);
// 		}
// 		else
// 		{
// 			right = mid;
// 			//print("Right devient: " << *right);
// 		}
// 	}

// 	if (*left > target && left - level > main.begin())
// 		left -= level;
// 	//nl;

// 	return left;
// }

// void	insertion_l(List &main, List::iterator pos, List::iterator element, size_t level)
// {
// 	// if (*pos > *element)
// 	// 	print("On veut inserer "  << *element << " a gauche de: " << *pos);
// 	// else
// 	// 	print("On veut inserer "  << *element << " a droite de: "  << *pos);
// 	// nl;

// 	if (*pos > *element && level > 1)
// 		main.insert(main.begin(), element - level + 1, element + 1);
// 	else if (*pos > *element && pos != main.begin())
// 		main.insert(pos, element - level + 1, element + 1);
// 	else if (*pos > *element)
// 		main.insert(main.begin(), element - level + 1, element + 1);
// 	else
// 	{
// 		if (pos < main.end())
// 			pos++;
// 		main.insert(pos, element - level + 1, element + 1);
// 	}

// 	// std::cout << "Main apres insertion: ";
// 	// for (List::iterator it = main.begin(); it < main.end(); it++)
// 	// 	std::cout << *it << ' ';
// 	// nl;
// }


// void	sorting_l(List &pairs, size_t level)
// {

// 	//print("On appelle insertion au level:" << level);
// 	Vect	pend;
// 	Vect	odd;
// 	build_pend(pairs, pend, odd, level);
// 	Vect	old_main = pairs;

// 	if (pend.empty())
// 		return ;

// 	// nl;
// 	// print("Level: " << level);
// 	// std::cout << "Pend: ";
// 	// for (Vect::iterator it = pend.begin(); it < pend.end(); it++)
// 	// 	std::cout << *it << ' ';
// 	// if (!odd.empty())
// 	// {
// 	// 	std::cout << " | Odd: ";
// 	// 	for (Vect::iterator it = odd.begin(); it < odd.end(); it++)
// 	// 		std::cout << *it << ' ';
// 	// }
// 	// nl;

// 	// nl;
// 	// std::cout << "Main: ";
// 	// for (Vect::iterator it = pairs.begin(); it < pairs.end(); it++)
// 	// 	std::cout << *it << ' ';
// 	// nl;


// 	unsigned int	Jacob[2] = {1, 3};
// 	unsigned int	n;
// 	Vect::iterator pos;

// 	while (Jacob[0] <= pend.size() / level)
// 	{
// 		//print(Jacob[0]);
// 		Vect::iterator b = pend.begin() + level - 1;
// 		n = 2;
// 		while (n != Jacob[1] && b + level < pend.end())
// 		{
// 			b += level;
// 			n++;
// 		}
// 		while (n > Jacob[0])
// 		{
// 			//print("Binary search de: " << *b << " pour element b" << n);
// 			pos = binary_search(*b, pairs, old_main, level, n, false);
// 			insertion(pairs, pos, b, level);
// 			b -= level;
// 			n--;
// 		}
// 		//nl;
// 		n = Jacob[1];
// 		Jacob[1] = (Jacob[0] * 2) + Jacob[1];
// 		Jacob[0] = n;
// 	}
// 	if (odd.size() >= level)
// 	{
// 		//print("Binary search de: " << odd.back() << " pour element odd nb jacob: " << n);
// 		pos = binary_search(odd.back(), pairs, old_main, level, n, true);
// 		insertion(pairs, pos, odd.end() - 1, level);
// 	}
// 	else if (!odd.empty())
// 	{
// 		for (Vect::iterator it = odd.begin(); it < odd.end(); it++)
// 			pairs.push_back(*it);
// 	}
// }


// void	build_pend(Vect &pairs, Vect &pend, Vect &odd, size_t level)
// {

// 	if (pairs.size() < level * 4)
// 		return ;

// 	for (Vect::iterator it = pairs.begin() + (2 * level); it < pairs.end(); it += level)
// 	{
// 		Vect::iterator k = it;
// 		if (it + (level * 2) >= pairs.end())
// 		{
// 			while (it < k + level && it < pairs.end())
// 			{
// 				odd.push_back(*it);
// 				it++;
// 			}
// 			break ;
// 		}
// 		while (it < k + level)
// 		{
// 			pend.push_back(*it);
// 			it++;
// 		}
// 	}
// 	for (Vect::iterator it = pend.begin(); it < pend.end(); it++)
// 	{
// 		for (Vect::iterator k = pairs.begin(); k < pairs.end(); k++)
// 		{
// 			if (*k == *it)
// 			{
// 				pairs.erase(k);
// 				break ;
// 			}
// 		}
// 	}
// 	if (!odd.empty())
// 	{
// 		for (Vect::iterator it = odd.begin(); it < odd.size() + odd.begin(); it++)
// 		{
// 			for (Vect::iterator k = pairs.begin(); k < pairs.end(); k++)
// 			{
// 				if (*k == *it)
// 				{
// 					pairs.erase(k);
// 					break ;
// 				}
// 			}
// 		}
// 	}
// 	return ;
// }

List::iterator	incr(List lst, List::iterator it, int n)
{
	size_t nb;

	if (n < 0)
		nb = -n;
	else
		nb = n;
	for (size_t i = 0; i < nb; i++)
	{
		if (it == lst.end() || it == lst.begin())
			return it;
		else if (n < 0)
			it--;
		else if (n > 0)
			it++;
	}
	return it;
}