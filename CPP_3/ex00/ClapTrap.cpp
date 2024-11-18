/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochetrit <ochetrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 16:44:25 by ochetrit          #+#    #+#             */
/*   Updated: 2024/11/15 18:01:52 by ochetrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void): _hp(10), _stamina(10), _ad(10){
	_name = std::string();
	std::cout << "Default constructor has been called" << std::endl;
}

ClapTrap::ClapTrap(const std::string name): _hp(10), _stamina(10), _ad(10){
	_name = name;
	std::cout << "Constructor has been called and ClapTrap will be named " << name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other){
	*this = other;
	std::cout << "Copy constructor has been called" << std::endl;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &other){
	this->_hp = other._hp;
	this->_stamina = other._stamina;
	this->_ad = other._ad;
	this->_name = other._name;
	return (*this);
}

ClapTrap::~ClapTrap(void){
	std::cout << "Destructor has been called, cy@" << std::endl;
	return ;
}

void	ClapTrap::attack(const std::string &target)
{
	if (this->_stamina == 0 || this->_hp == 0)
	{
		std::cout << "ClapTrap " << _name  << " can't do anything, need to rest" << std::endl;
		return ;
	}
	this->_stamina--;
	std::cout << "ClapTrap " << _name << " attacks " << target << ", causing ";
	std::cout  << _ad << " points of damage!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (_hp == 0)
		std::cout << "I think you should stop attack "<< _name << ", it's over now..." << std::endl;
	else if (amount >= _hp)
	{
		std::cout << "ClapTrap " << _name << " lose " << _hp << " and is now K.O" << std::endl;
		_hp = 0;
	}
	else
	{
		_hp -= amount;
		std::cout << "ClapTrap " << _name << " lose " << _hp << " and has now " << _hp << " hp." << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_stamina == 0 || this->_hp == 0)
	{
		std::cout << "ClapTrap " << _name << " can't do anything, need to rest" << std::endl;
		return ;
	}
	_stamina--;
	_hp += amount;
	std::cout << "ClapTrap " << _name << " has now " << _hp << " hp"<< std::endl;
}
