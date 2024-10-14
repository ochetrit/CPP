/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochetrit <ochetrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 16:43:46 by ochetrit          #+#    #+#             */
/*   Updated: 2024/09/17 15:06:48 by ochetrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(int ac, char **av)
{
	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
	}
	else
	{
		for (std::string MonArg : av)
		{
			for (char c : MonArg)
			{
				if (c <= 'z' && c >= 'a')
					std::cout << c - 'a' + 'A';
				else
					std::cout << c;
			}
		}
		std::cout << std::end1;
	}
	return (0);
}
