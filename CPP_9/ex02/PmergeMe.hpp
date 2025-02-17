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
#include <deque>
#include <string>
#include <cstring>
#include <cstdlib>
#include <limits>
#include <algorithm>
#include <utility>
#include <iomanip>
#include <ctime>
#include <cstdlib>

#define nl std::cout << std::endl
#define print(x) std::cout << x << std::endl
#define perr(x) std::cerr << x << std::endl
#define Vect std::vector<int>
#define Deque std::deque<int>


///					MAIN					///

bool	parse_args(char **av, int ac, Vect &elmnt);
//void	fill_pairs(Vect &pairs, Vect elmnt);


///					PMERGE					///

void	sorting_pair(Vect &pairs, size_t level);
void	sorting(Vect &pairs, size_t level);
void	build_pend(Vect &pairs, Vect &pend, Vect &odd, size_t level);

void	sorting_pair_dq(Deque &pairs, size_t level);
void	sorting_dq(Deque &pairs, size_t level);
void	build_pend_dq(Deque &pairs, Deque &pend, Deque &odd, size_t level);