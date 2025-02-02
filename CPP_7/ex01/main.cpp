/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochetrit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 14:22:22 by ochetrit          #+#    #+#             */
/*   Updated: 2025/02/02 14:22:22 by ochetrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main()
{
	std::cout << "With an array of int" << std::endl;

	int	array[7] = {0, 1, 2, 3, 4, 5, 6};

	iter(array, 7, display);

	std::cout << std::endl <<  "With an array of float" << std::endl;
	
	float	array2[7] = {0.01f, 0.02f, 0.03f, 0.04f, 0.05f, 0.06f, 0.07f};

	iter(array2, 7, display);

	std::cout << std::endl <<  "With an array of strings" << std::endl;
	
	const char	*array3[4] = {"Bonjour !", "-Ca va ?", "-Oui et toi ?", "-Oui, merci."};

	iter(array3, 4, display);
}