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

Dog::Dog(void):Animal(), _brain(){
	type = "Dog";
	_brain = new Brain();
	_brain->newIdea(99, "I want to WALK");
	std::cout << "A wild Dog appeared !" << std::endl;
	return ;
}

Dog::Dog(const Dog &other):Animal(other), _brain(){
	_brain = new Brain();
	std::cout << "Copy Dog" << std::endl;
	*this = other;
}

Dog	&Dog::operator=(const Dog &other){
	if (_brain)
		delete _brain;
	if (this != &other)
	{
		type = other.type;
		_brain = new Brain(*other.getBrain());
	}
	return (*this);
}

Dog::~Dog(void){
	delete _brain;
	std::cout << "Dog fainted!" << std::endl;
}

Brain	*Dog::getBrain(void) const{
	return (_brain);
}

void	Dog::makeSound(void) const{
	std::cout << this->getType() << " be like : " << "*bark*" << std::endl;
}