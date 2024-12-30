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
#include "Brain.hpp"


int main()
{
	Dog stupid;

	std::cout << std::endl;

	Dog smart(stupid);

	std::cout << "Adress stupid : " << stupid.getBrain() << std::endl;
	std::cout << "Adress smart : " << smart.getBrain() << std::endl;
	std::cout << "Not the same adress" << std::endl;

	Animal *(array[4]);
	std::cout << std::endl;

	for (int i = 0; i < 4; i++)
	{
		if (i % 2)
			array[i] = new Cat;
		else
			array[i] = new Dog;
	}
	for (int i = 0; i < 4; i++){
		delete array[i];
	}
}
