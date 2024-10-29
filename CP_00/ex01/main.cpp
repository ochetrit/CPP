/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochetrit <ochetrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 19:31:52 by ochetrit          #+#    #+#             */
/*   Updated: 2024/10/29 18:48:18 by ochetrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	check_input(std::string command)
{
	for (std::size_t i = 0; i < command.length(); i++)
	{
		if (std::isspace(command[i]) != 0)
			return (1);
		if (std::isalnum(command[i]) == 0)
			return (0);
	}
	return (1);
}

int main()
{
	std::cout << "Enter your command [ADD, SEARCH, EXIT]:" << std::endl;
	std::string command;
	PhoneBook phonebook;
	
	while (std::getline(std::cin, command))
	{
		if (check_input(command) == 0)
			std::cout << "I only accept alphanum caracters" << std::endl;
		else if (command.compare("ADD") == 0)
			phonebook.cmd_add();
		else if (command.compare("SEARCH") == 0)
			std::cout << "SEARCH" << std::endl;
		else if (command.compare("EXIT") == 0)
			break ;
		else
			std::cout << "Invalid command" << std::endl;
	}
	std::cout << "Looks like it's over for me. Goodbye !" << std::endl;
			return (1);
}
