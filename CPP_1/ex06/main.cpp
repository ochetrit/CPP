/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochetrit <ochetrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 16:43:46 by ochetrit          #+#    #+#             */
/*   Updated: 2024/11/04 19:15:48 by ochetrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Harl.hpp"

int	Translating(std::string arg, std::string levels[5])
{
	for (int i = 0; i < 4; i++){
		if (arg == levels[i])
			return (i);
	}
	std::cout << "Harl has eaten enough cheese for now !" << std::endl;
	return (1);
}

void	HarlemSwitch(char *arg, Harl &h)
{
	switch (Translating(std::string(arg), h.levels))
	{
	case 0:
		h.complain("DEBUG");
	case 1:
		h.complain("INFO");
	case 2:
		h.complain("WARNING");
	case 3:
		h.complain("ERROR");
		break ;
	default:
		std::cout << "Harl has eaten enough cheese for now !" << std::endl;
	}
}

int main(int ac, char **av)
{
	if (ac != 2){
		std::cout << "Harl has eaten enough cheese for now !" << std::endl;
		return (1);
	}
	Harl h;
	HarlemSwitch(av[1], h);
	return (0);
}
