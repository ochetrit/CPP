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

#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
	this->type = type;
}

Weapon::~Weapon(void)
{
	return ;
}

std::string const &Weapon::getType(void)
{
	return (this->type);
}

void Weapon::setType(std::string newtype)
{
	this->type = newtype;
}
