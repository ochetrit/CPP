/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochetrit <ochetrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 16:44:11 by ochetrit          #+#    #+#             */
/*   Updated: 2024/12/27 14:41:34 by ochetrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void):AAnimal(), _brain(){
	type = "Cat";
	_brain = new Brain();
	_brain->newIdea(99, "I have 9 lifes");
	std::cout << "A wild Cat appeared !" << std::endl;
	return ;
}

Cat::Cat(const Cat &other):AAnimal(other), _brain(){
	std::cout << "Copy Cat" << std::endl;
	_brain = new Brain();
	*this = other;
}

Cat	&Cat::operator=(const Cat &other){
	if (this != &other) {
		type = other.type;
		_brain = new Brain(*other.getBrain());
	}
	return (*this);
}

Cat::~Cat(void){
	delete _brain;
	std::cout << "Cat fainted!" << std::endl;
}

Brain	*Cat::getBrain(void) const{
	return (_brain);
}

void	Cat::makeSound(void) const{
	std::cout << this->getType() << " be like : "<< "*meow*" << std::endl;
}
