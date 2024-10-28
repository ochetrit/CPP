/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochetrit <ochetrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 20:03:58 by ochetrit          #+#    #+#             */
/*   Updated: 2024/10/28 18:22:06 by ochetrit         ###   ########.fr       */
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
