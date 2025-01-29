/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochetrit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 16:08:07 by ochetrit          #+#    #+#             */
/*   Updated: 2024/12/30 16:08:08 by ochetrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
	print("Max float: " << std::numeric_limits<float>::max() << std::endl;
    std::cout << "Min float: " << std::numeric_limits<float>::min());
	if (ac != 2)
	{
		print("Error, I need one argument");
		return (1);
	}
	std::string arg = av[1];
	if (ScalarConverter::is_float(arg))
		print("C'est un float");
	else
		print("C'est pas un float");

}
