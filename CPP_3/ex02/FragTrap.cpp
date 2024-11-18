/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochetrit <ochetrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:06:07 by ochetrit          #+#    #+#             */
/*   Updated: 2024/11/18 17:09:57 by ochetrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void){
	std::cout << "WHO AM I ?" << std::endl;
	_hp= 100; _stamina = 100; _ad = 30;
}

FragTrap::FragTrap(FragTrap &other){
	*this = other;
}

FragTrap::FragTrap(const std::string name){
	_name = name;
	_hp= 100; _stamina = 100; _ad = 30;
	std::cout << "Constructor has been called and FragTrap will be named " << name << std::endl;
}

FragTrap::~FragTrap(void){
	std::cout << "This O.V.N.I is destroyed." << std::endl;
}

FragTrap &FragTrap::operator=(FragTrap &other){
	_hp = other._hp;
	_stamina = other._stamina;
	_ad = other._ad;
	_name = other._name;
	return (*this);
}

void	FragTrap::attack(const std::string &target)
{
	if (this->_stamina == 0 || this->_hp == 0)
	{
		std::cout << "FragTrap " << _name  << " can't do anything, need to rest." << std::endl;
		return ;
	}
	this->_stamina--;
	std::cout << "FragTrap " << _name << " attacks " << target << ", causing ";
	std::cout  << _ad << " points of damage!" << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "For sure I'll high five, yeaaay ?!" << std::endl;
}
