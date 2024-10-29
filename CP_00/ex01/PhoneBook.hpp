/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochetrit <ochetrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 19:31:36 by ochetrit          #+#    #+#             */
/*   Updated: 2024/10/29 18:13:04 by ochetrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include <iostream>
# include <string>
#include "Contact.hpp"

class Contact;

class PhoneBook
{
	private :
	Contact BookContact[8];
	int	size;
	bool	full;

	public :
	PhoneBook(void);
	~PhoneBook(void);
	void cmd_add(void);
};

#endif