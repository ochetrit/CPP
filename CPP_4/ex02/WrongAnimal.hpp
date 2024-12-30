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

# ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>
# include <string>

class WrongAnimal
{
	protected :

	std::string type;

	public :

	WrongAnimal();
	WrongAnimal(const WrongAnimal &other);

	WrongAnimal &operator=(const WrongAnimal &other);
	
	virtual ~WrongAnimal();

	std::string getType(void) const;
	virtual void makeSound(void) const;
};

#endif