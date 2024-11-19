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
#include "Dog.hpp"
#include "WrongCat.hpp"


int main()
{
	const Animal* meta = new Animal();
	const Animal* q = new Dog();
	const Animal* i = new Cat();
	const Animal j = *q;
	const WrongAnimal* notmeta = new WrongAnimal();
	const WrongAnimal* z = new WrongCat();
	std::cout << "j is a " << j.getType() << std::endl;
	std::cout << "i is a " << i->getType() << std::endl;
	std::cout << "z is a " << z->getType() << std::endl;
	i->makeSound(); //will output the cat sound!
	j.makeSound();
	meta->makeSound();
	z->makeSound();
	notmeta->makeSound();
	delete q;
	delete i;
	delete meta;
	delete z;
	delete notmeta;
	return 0;
}