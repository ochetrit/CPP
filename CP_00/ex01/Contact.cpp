/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochetrit <ochetrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 20:03:58 by ochetrit          #+#    #+#             */
/*   Updated: 2024/10/29 18:52:53 by ochetrit         ###   ########.fr       */
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

int	check_input_phone(std::string input)
{
	if (input.length() != 10)
		return (0);
	for (std::size_t i = 0; i < input.length(); i++)
	{
		if (std::isdigit(input[i]) == 0)
			return (0);
	}
	return (1);
}

int	check_input_secret(std::string input)
{
	for (std::size_t i = 0; i < input.length(); i++)
	{
		if (std::isalnum(input[i]) == 0 && std::isspace(input[i]) == 0)
			return (0);
	}
	return (1);
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
				std::cout << "You must enter a valid " << Contact::fields_name[i] << std::endl;
			else if (input.empty() || (check_input_phone(input) == 0 && i == PhoneNumber))
				std::cout << "You must enter a valid phone number " << std::endl;
			else if (input.empty() || (check_input_secret(input) == 0 && i == DarkestSecret))
				std::cout << "You must enter a valid DarkestSecret" << std::endl;
			else
			{
				this->informations[i] = input;
				break ;
			}
		}
	}
}

void	Contact::display_contact_name(void)
{
	std::string display;

	for (int i = FirstName; i <= NickName; i++)
	{
		display = this->informations[i];
		if (display.length() > 10)
		{
			display.resize(9);
			display += ".";
		}
		std::cout << std::setw(10) << display << "|";
	}
	std::cout << std::endl;
}

void	Contact::display_contact(void)
{
	for (int i = FirstName; i <= DarkestSecret; i++)
	{
		std::cout << this->informations[i] << std::endl;
	}
}