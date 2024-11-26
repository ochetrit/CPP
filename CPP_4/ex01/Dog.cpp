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

#include "Dog.hpp"

Dog::Dog(void):Animal(){
	type = "Dog";
	_brain->newIdea(99, "I want to WALK");
	std::cout << "A wild Dog appeared !" << std::endl;
	return ;
}

Dog::Dog(const Dog &other):Animal(other){
	*this = other;
}

Dog	&Dog::operator=(const Dog &other){
	if (this != &other)
		type = other.type;
	return (*this);
}

Dog::~Dog(void){
	std::cout << "Dog fainted!" << std::endl;
}

void	Dog::makeSound(void) const{
	std::cout << this->getType() << " be like : " << "*bark*" << std::endl;
}