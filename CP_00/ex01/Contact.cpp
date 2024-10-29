/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochetrit <ochetrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 20:03:58 by ochetrit          #+#    #+#             */
/*   Updated: 2024/10/29 18:49:49 by ochetrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

std::string Contact::fields_name[5] =
{
	"FirstName",
	"LastName",
	"NickName",
	"PhoneNumber",
	"DarkestSecret"
};

Contact::Contact(void)
{
	for (int i = FirstName; i <= DarkestSecret; i++)
		this->informations[i] = std::string();
	return ;
}

Contact::~Contact(void)
{
	return ;
}

void	Contact::add_contact(void)
{
	std::string input;

	for (int i = FirstName; i <= DarkestSecret; i++)
	{
		while (1)
		{
			std::cout << "Enter your " << Contact::fields_name[i] << ": ";
			if (!std::getline(std::cin, input))
			{
				std::cout << "You pressed Ctrl+D, see you soon i hope. Goodbye !" << std::endl;
				exit(0);
			}
			else if (input.empty() || (check_input(input) == 0 && i < PhoneNumber))
				std::cout << "You must enter a value" << std::endl;
			else if (input.empty())
			else
			{
				this->informations[i] = input;
				break ;
			}
		}
	}
}