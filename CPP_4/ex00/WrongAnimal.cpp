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

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void):type(){
	type = "WrongAnimal";
	std::cout << "A wild WrongAnimal appeared !" << std::endl;
	return ;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other):type(){
	std::cout << "Copy Wrong Animal" << std::endl;
	*this = other;
}

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &other){
	if (*type != other)
		type = other.type;
	return (*this);
}

WrongAnimal::~WrongAnimal(void){
	std::cout << "WrongAnimal fainted!" << std::endl;
}

std::string WrongAnimal::getType(void) const{
	return (type);
}

void	WrongAnimal::makeSound(void) const{
	std::cout << this->getType() << " be like : " << "*quiet*" << std::endl;
}