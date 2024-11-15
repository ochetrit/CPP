/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochetrit <ochetrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:51:57 by ochetrit          #+#    #+#             */
/*   Updated: 2024/11/06 19:17:09 by ochetrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H
# include <iostream>
# include <math.h>

class Fixed
{
private :
	int	fp_nb;
	static const int nf_bits;

public :
	Fixed( void );
	Fixed(const int input);
	Fixed(const float input);
	Fixed(const Fixed& other);
	
	~Fixed( void );
	
	float	toFloat(void) const;
	int		toInt(void)const;
	int 	getRawBits(void) const;
	void 	setRawBits(int const raw);

	///Operator :

	Fixed &operator=(const Fixed &other);
	Fixed operator++(void);
	Fixed operator++(int);
	Fixed operator--(void);
	Fixed operator--(int);

	bool operator>(const Fixed &other) const;
	bool operator>=(const Fixed &other) const;
	bool operator<(const Fixed &other) const;
	bool operator<=(const Fixed &other) const;
	bool operator==(const Fixed &other) const;
	bool operator!=(const Fixed &other) const;

	float operator+(const Fixed &other) const;
	float operator-(const Fixed &other) const;
	float operator*(const Fixed &other) const;
	float operator/(const Fixed &other) const;

	static Fixed	&min(Fixed &first, Fixed &second);
	const static Fixed	&min(const Fixed &first, const Fixed &second);
	static Fixed	&max(Fixed &first, Fixed &second);
	const static Fixed	&max(const Fixed &first, const Fixed &second);
};

std::ostream &operator<<(std::ostream &fd, const Fixed &other);

#endif
