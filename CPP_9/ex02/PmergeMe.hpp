/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochetrit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:45:37 by ochetrit          #+#    #+#             */
/*   Updated: 2025/02/06 12:45:39 by ochetrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once


#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <cstring>
#include <cstdlib>
#include <limits>
#include <algorithm>
#include <utility>

#define nl std::cout << std::endl
#define print(x) std::cout << x << std::endl
#define perr(x) std::cerr << x << std::endl
#define Vect std::vector<int>
#define Pair std::vector<std::pair<int, int> >


///					MAIN					///

bool	parse_args(char **av, int ac, Vect &elmnt);
void	fill_pairs(Pair &pairs, Vect elmnt);


///					PMERGE					///

void	sorting_pair(Pair &pairs, size_t level);
void	insertion(Pair pairs, size_t level);