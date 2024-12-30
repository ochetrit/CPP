/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochetrit <ochetrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 16:44:11 by ochetrit          #+#    #+#             */
/*   Updated: 2024/11/15 17:19:07 by ochetrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void):type(){
	type = "Animal";
	std::cout << "A wild Animal appeared !" << std::endl;
	return ;
}

Animal::Animal(const Animal &other):type(){
	*this = other;
}

Animal	&Animal::operator=(const Animal &other){
	if (this != &other)
		type = other.type;
	return (*this);
}

Animal::~Animal(void){
	std::cout << "Animal fainted!" << std::endl;
}

std::string Animal::getType(void) const{
	return (type);
}

void	Animal::makeSound(void) const{
	std::cout << this->getType() << " be like : " << "*strange noise*" << std::endl;
}