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
	
	Fixed &operator=(const Fixed &other);
	float	toFloat(void) const;
	int		toInt(void)const;
	int 	getRawBits(void) const;
	void 	setRawBits(int const raw);	
};

std::ostream &operator<<(std::ostream &fd, const Fixed &other);


#endif
