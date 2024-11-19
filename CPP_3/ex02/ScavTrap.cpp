/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochetrit <ochetrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 12:44:04 by ochetrit          #+#    #+#             */
/*   Updated: 2024/11/18 16:59:41 by ochetrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void): ClapTrap(){
	std::cout << "I AM NOT A CLAPTRAP" << std::endl;
	_hp= 100; _stamina = 50; _ad = 20;
}

ScavTrap::ScavTrap(ScavTrap &other): ClapTrap(other){
	*this = other;
}

ScavTrap::ScavTrap(const std::string name): ClapTrap(name + "_CP"){
	_name = name;
	_hp= 100; _stamina = 50; _ad = 20;
	std::cout << "Constructor has been called and ScavTrap will be named " << name << std::endl;
}

ScavTrap::~ScavTrap(void){
	std::cout << "NOT A CLAPTRAP IS DESTROYED." << std::endl;
}

ScavTrap &ScavTrap::operator=(ScavTrap &other){
	if (this != &other)
		ClapTrap::operator=(other);
	return (*this);
}

void	ScavTrap::attack(const std::string &target)
{
	if (this->_stamina == 0 || this->_hp == 0)
	{
		std::cout << "ScavTrap " << _name  << " can't do anything, need to rest." << std::endl;
		return ;
	}
	this->_stamina--;
	std::cout << "ScavTrap " << _name << " attacks " << target << ", causing ";
	std::cout  << _ad << " points of damage!" << std::endl;
}


void	ScavTrap::guardGate(void)
{
	std::cout << "I AM IN KEEPERMODE BIPBOPBOP !" << std::endl;
}
