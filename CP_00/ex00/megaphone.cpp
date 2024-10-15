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
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	}
	else
	{
		int i = 0;
		int j;
		while (av[i++] != NULL)
		{
			j = 0;
			while (av[i][j] != '\0')
			{
				if (av[i][j] <= 'z' && av[i][j] >= 'a')
					av[i][j] +=  'A' - 'a';
				std::cout << av[i][j];
				j++;
			}
			i++;
		}
		std::cout << std::endl;
	}
	return (0);
}
