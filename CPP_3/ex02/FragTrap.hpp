/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochetrit <ochetrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:06:02 by ochetrit          #+#    #+#             */
/*   Updated: 2024/11/18 17:09:06 by ochetrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
# include "ClapTrap.hpp"

class FragTrap: public ClapTrap
{
	public :
	FragTrap(void);
	FragTrap(FragTrap &other);
	FragTrap(const std::string name);
	
	~FragTrap(void);
	
	FragTrap &operator=(FragTrap &other);

	void	attack (const std::string &target);
	void	highFivesGuys(void);
};


#endif
