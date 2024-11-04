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

#include "HumanB.hpp"

HumanB::HumanB(std::string name):name(name), weapon(NULL)
{
	this->weapon_set = false;
	std::cout << this->name << " has arrived on the battlefields without weapon, this human is insane!" << std::endl;
	return ;
}

HumanB::~HumanB(void)
{
	std::cout << this->name << " thinks peace is a better solution" << std::endl;
	return ;
}

void HumanB::setWeapon(Weapon *weapon)
{
	this->weapon = weapon;
	this->weapon_set = true;
}

void HumanB::attack(void)
{
	if (!this->weapon_set)
		std::cout << this->name << " does not attack because he just arrived with his bare hands" << std::endl;
	else
		std::cout << this->name << " attacks with their " << (*this->weapon).getType() << std::endl;
	return ;
}
