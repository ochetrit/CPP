/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochetrit <ochetrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 16:43:46 by ochetrit          #+#    #+#             */
/*   Updated: 2024/11/04 19:15:48 by ochetrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

std::string Harl::levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

Harl::Harl(void)
{
	std::cout << "I'm not boring but I really appreciate cheese..." << std::endl;
}

Harl::~Harl(void)
{
	std::cout << "I hope i will have more cheese next time, good bye !" << std::endl;
}

void Harl::debug(void)
{
	std::cout << "I love having extra cheese for my 7XL-double-cheese-triple";
	std::cout << "-pickle-specialketchup burger. I really do !" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra cheese for free. I've ";
	std::cout << "been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::info(void)
{
	std::cout << "I cannot believe adding extra cheese costs more money. You didn't";
	std::cout << " put enough cheese in my burger ! If you did, I wouldn't be asking for more !" << std::endl;
}

void Harl::error(void)
{
	std::cout << "This is unacceptable ! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
	void (Harl::*ptrcomplain[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	for (int i = 0; i < 4; i++){
		if (levels[i] == level)
			(this->*ptrcomplain[i])();
	}
}