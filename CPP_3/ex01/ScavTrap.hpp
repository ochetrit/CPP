/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochetrit <ochetrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 12:43:58 by ochetrit          #+#    #+#             */
/*   Updated: 2024/11/18 16:47:49 by ochetrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
# include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
	public :
	ScavTrap(void);
	ScavTrap(ScavTrap &other);
	ScavTrap(const std::string name);
	
	~ScavTrap(void);
	
	ScavTrap &operator=(ScavTrap &other);

	void	attack (const std::string &target);
	void	guardGate(void);
};


#endif
