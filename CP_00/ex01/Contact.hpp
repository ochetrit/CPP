/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochetrit <ochetrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 20:03:54 by ochetrit          #+#    #+#             */
/*   Updated: 2024/10/28 18:20:32 by ochetrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP
# include <string>
# include <iostream>
# include "PhoneBook.hpp"

class Contact
{
	private :
	std::string informations[5];
	std::string static fields_name[5];
	enum Field
	{
		FirstName = 0,
		LastName,
		NickName,
		PhoneNumber,
		DarkestSecret
	};
		
	public :
	Contact(void);
};

#endif