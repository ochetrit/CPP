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
	//std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::Fixed(const int input)
{
	//std::cout << "Int constructor called" << std::endl;
	this->fp_nb = roundf(input * (1 << nf_bits));
}

Fixed::Fixed(const float input)
{
	//std::cout << "Float constructor called" << std::endl;
	this->fp_nb = roundf(input * (1 << nf_bits));
}

Fixed::Fixed(const Fixed& other)
{
	//std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed::~Fixed(void)
{
	//std::cout << "Destructor called" << std::endl;
	return ;
}

float Fixed::toFloat(void) const
{
	return (((float)fp_nb / (1 << nf_bits)));
}

int Fixed::toInt(void) const
{
	return (fp_nb >> nf_bits);
}

int Fixed::getRawBits(void) const
{
	return (fp_nb);
}

void	Fixed::setRawBits(int const raw)
{
	this->fp_nb = raw;
	std::cout << "setRawBits member function called" << std::endl;
}

	/// OPERATOR ///

Fixed &Fixed::operator=(const Fixed &other)
{
	//std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->fp_nb = other.getRawBits();
	return *this;
}

std::ostream &operator<<(std::ostream &fd, const Fixed &other)
{
	fd << other.toFloat();
	return (fd);
}

bool Fixed::operator>(const Fixed &other) const{
	return (this->fp_nb > other.fp_nb);
}

bool Fixed::operator>=(const Fixed &other) const{
	return (this->fp_nb >= other.fp_nb);
}

bool Fixed::operator<(const Fixed &other) const{
	return (this->fp_nb < other.fp_nb);
}

bool Fixed::operator<=(const Fixed &other) const{
	return (this->fp_nb <= other.fp_nb);
}

bool Fixed::operator==(const Fixed &other) const{
	return (this->fp_nb == other.fp_nb);
}

bool Fixed::operator!=(const Fixed &other) const{
	return (this->fp_nb != other.fp_nb);
}

float Fixed::operator+(const Fixed &other) const{
	return (this->toFloat() + other.toFloat());
}

float Fixed::operator-(const Fixed &other) const{
	return (this->toFloat() - other.toFloat());
}

float Fixed::operator*(const Fixed &other) const{
	return (this->toFloat() * other.toFloat());
}

float Fixed::operator/(const Fixed &other) const
{
	if (other.fp_nb == 0){
		std::cerr << "This is mathematically forbidden" << std::endl;
		exit(1);
	}
	return (this->toFloat() / other.toFloat());
}

Fixed Fixed::operator++(void){
	this->fp_nb++;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed tmp = *this;
	this->fp_nb++;
	return (tmp);
}

Fixed Fixed::operator--(void){
	this->fp_nb--;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp = *this;
	this->fp_nb--;
	return (tmp);
}

Fixed	&Fixed::min(Fixed &first, Fixed &second)
{
	if (first <= second)
		return (first);
	else
		return (second);
}

const Fixed	&Fixed::min(const Fixed &first, const Fixed &second)
{
	if (first <= second)
		return (first);
	else
		return (second);
}

Fixed	&Fixed::max(Fixed &first, Fixed &second)
{
	if (first >= second)
		return (first);
	else
		return (second);
}

const Fixed	&Fixed::max(const Fixed &first, const Fixed &second)
{
	if (first >= second)
		return (first);
	else
		return (second);
}
