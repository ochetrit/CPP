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

#include "AAnimal.hpp"

AAnimal::AAnimal(void):type(){
	type = "AAnimal";
	std::cout << "A wild AAnimal appeared !" << std::endl;
	return ;
}

AAnimal::AAnimal(const AAnimal &other):type(){
	*this = other;
}

AAnimal	&AAnimal::operator=(const AAnimal &other){
	if (this != &other)
		type = other.type;
	return (*this);
}

AAnimal::~AAnimal(void){
	std::cout << "AAnimal fainted!" << std::endl;
}

std::string AAnimal::getType(void) const{
	return (type);
}

void	AAnimal::makeSound(void) const{
	std::cout << this->getType() << " be like : " << "*strange noise*" << std::endl;
}