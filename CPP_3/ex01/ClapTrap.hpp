/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochetrit <ochetrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 16:44:11 by ochetrit          #+#    #+#             */
/*   Updated: 2024/11/18 15:53:59 by ochetrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class ClapTrap
{
	protected:
	
	std::string _name;
	unsigned int _hp;
	unsigned int _stamina;
	unsigned int _ad;
	
	public:
	
	ClapTrap(void);
	ClapTrap(const std::string name);
	ClapTrap(const ClapTrap &other);
	
	ClapTrap	&operator=(const ClapTrap &other);
	
	virtual ~ClapTrap(void);
	
	virtual void attack(const std::string &target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
};

#endif