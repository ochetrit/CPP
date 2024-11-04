/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochetrit <ochetrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 19:31:44 by ochetrit          #+#    #+#             */
/*   Updated: 2024/11/04 19:17:09 by ochetrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	this->full = false;
	this->size = 0;
	return ;
}

PhoneBook::~PhoneBook(void)
{
	return ;
}

void	PhoneBook::cmd_add(void)
{
	if (this->size < 8)
	{
		this->BookContact[this->size].add_contact();
		this->size++;
		if (this->size == 8)
			this->full = true;
	}
	else if (this->full == true)
	{
		for (int i = 0; i < 7; i++)
		{
			this->BookContact[i] = this->BookContact[i + 1];
		}
		this->BookContact[7].add_contact();
	}
}

void	PhoneBook::cmd_search(void)
{
	if (this->size == 0)
	{
		std::cout << "No contact in the phonebook" << std::endl;
		return ;
	}
	std::cout << "     index|first name| last name|  nickname" << std::endl;
	for (int i = 0; i < this->size; i++)
	{
		std::cout << std::setw(10) << i + 1 << "|";
		this->BookContact[i].display_contact_name();
	}
	std::cout << "Enter the index that i'll display" << std::endl;
	std::string index;
	while(std::getline(std::cin, index))
	{
		if (index.length() != 1 || std::isdigit(index[0]) == 0 || index[0] - '0' > this->size || index[0] - '0' < 1)
			std::cout << "Invalid index" << std::endl;
		else
		{
			this->BookContact[index[0] - '0' - 1].display_contact();
			return ;
		}
	}
	std::cout << "You pressed Ctrl+D, see you soon i hope. Goodbye !" << std::endl;
	exit(1);
}