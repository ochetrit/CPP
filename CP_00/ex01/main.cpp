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
		if (std::isalnum(command[i]) == 0)
			return (0);
	}
	return (1);
}

int main()
{
	std::string command;
	PhoneBook phonebook;

	std::cout << "Enter your command [ADD, SEARCH, EXIT]:" << std::endl;
	while (std::getline(std::cin, command))
	{
		if (check_input(command) == 0)
			std::cout << "I only accept alphanum caracters" << std::endl;
		else if (command.compare("ADD") == 0)
			phonebook.cmd_add();
		else if (command.compare("SEARCH") == 0)
			phonebook.cmd_search();
		else if (command.compare("EXIT") == 0)
			return (std::cout << "Looks like it's over for me. Goodbye !" << std::endl, 0);
		else
			std::cout << "Invalid command" << std::endl;
		std::cout << "Enter your command [ADD, SEARCH, EXIT]:" << std::endl;
	}
	std::cout << "You pressed Ctrl+D, see you soon i hope. Goodbye !" << std::endl;
			return (1);
}
