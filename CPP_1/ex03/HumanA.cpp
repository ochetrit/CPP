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

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon): name(name), weapon(weapon)
{
	std::cout << this->name << " has arrived on the battlefield with " << this->weapon.getType() << "!" << std::endl;
	return ;
}

HumanA::~HumanA(void)
{
	std::cout << this->name << " thinks peace is a better solution" << std::endl;
	return ;
}

void HumanA::attack(void)
{
	std::cout << this->name << " attacks with their " << this->weapon.getType() << std::endl;
	return ;
}
