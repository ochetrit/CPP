/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochetrit <ochetrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 17:54:13 by ochetrit          #+#    #+#             */
/*   Updated: 2024/11/18 17:17:47 by ochetrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

int main()
{
	FragTrap b("Cody");
	FragTrap a = b;
	ClapTrap c("Clapclap");
	ScavTrap d("Fraggito");

	a.attack("some other robot");
	a.takeDamage(10);
	a.takeDamage(10);
	a.beRepaired(5);
	a.attack("some other other robot");
	b.beRepaired(3);
	for (int i = 0; i < 12; i++)
		b.attack("Cody-clone");
	b.beRepaired(3);
	d.guardGate();
	d.guardGate();
	c.beRepaired(1000);
	a.highFivesGuys();
	return (0);
}