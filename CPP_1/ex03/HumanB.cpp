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

HumanB::HumanB(std::string name):
{
	this->name = name;
	this->weapon = NULL;
	return ;
}

HumanB::~HumanB(void)
{
	return ;
}

void HumanB::setWeapon(Weapon weapon)
{
	this->weapon = weapon;
}

void HumanB::attack(void)
{
	if (!this->weapon)
		std::cout << this->name << " does not attack because he is unarmed" << std::endl;
	else
		std::cout << this->name << " attacks with his " << this->weapon.getType() << std::endl;
	return ;
}
