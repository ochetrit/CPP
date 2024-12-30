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

#ifndef CAT_HPP
# define CAT_HPP

# include "AAnimal.hpp"

class Cat: public AAnimal
{
	private:

	Brain *_brain;

	public :

	Cat();
	Cat(const Cat &other);

	Cat &operator=(const Cat &other);
	
	~Cat();

	Brain	*getBrain() const;
	void	makeSound(void) const;
};

#endif