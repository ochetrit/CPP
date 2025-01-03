/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochetrit <ochetrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:51:50 by ochetrit          #+#    #+#             */
/*   Updated: 2024/11/06 19:17:41 by ochetrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::nf_bits = 8;

Fixed::Fixed(void): fp_nb(0){
	std::cout << "Default constructor called" << std::endl;
	return ;
}

/* Fixed::Fixed(const Fixed& other): fp_nb(other.getRawBits()){
	std::cout << "Copy constructor called" << std::endl;
	return ;
} */

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->fp_nb = other.getRawBits();
	return *this;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (fp_nb);
}

void	Fixed::setRawBits(int const raw)
{
	this->fp_nb = raw;
	std::cout << "setRawBits member function called" << std::endl;
}