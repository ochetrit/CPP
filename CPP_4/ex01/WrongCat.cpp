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

#include "WrongCat.hpp"

WrongCat::WrongCat(void):WrongAnimal(){
	type = "WrongCat";
	std::cout << "A wild WrongCat appeared !" << std::endl;
	return ;
}

WrongCat::WrongCat(const WrongCat &other):WrongAnimal(other){
	*this = other;
}

WrongCat	&WrongCat::operator=(const WrongCat &other){
	if (this != &other)
		type = other.type;
	return (*this);
}

WrongCat::~WrongCat(void){
	std::cout << "WrongCat fainted!" << std::endl;
}

void	WrongCat::makeSound(void) const{
	std::cout << this->getType() << " be like : "<< "*wrong meow*" << std::endl;
}