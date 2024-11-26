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

#include "Cat.hpp"

Cat::Cat(void):Animal(){
	type = "Cat";
	_brain->newIdea(99, "I have 9 lifes");
	std::cout << "A wild Cat appeared !" << std::endl;
	return ;
}

Cat::Cat(const Cat &other):Animal(other){
	*this = other;
}

Cat	&Cat::operator=(const Cat &other){
	if (this != &other)
		type = other.type;
	return (*this);
}

Cat::~Cat(void){
	std::cout << "Cat fainted!" << std::endl;
}

void	Cat::makeSound(void) const{
	std::cout << this->getType() << " be like : "<< "*meow*" << std::endl;
}