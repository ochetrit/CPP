/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochetrit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:43:20 by ochetrit          #+#    #+#             */
/*   Updated: 2025/02/05 16:43:20 by ochetrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"


int	main(int ac, char **av)
{
	if (ac != 2)
	{
		perr("I need one argument.");
		return 1;
	}

	std::string arg(av[1]);
	RPN	rpn;
	std::string everychar = "0123456789+-*/";

	if (arg.size() == 0)
	{
		perr("It's an empty string...");
		return 2;
	}
	try
	{
		for (size_t i = 0; i < arg.size(); i++)
		{
			if (arg[i] == ' ')
				continue ;
			else if (everychar.find(arg[i], 0) == std::string::npos)
				throw RPN::ExceptionFormat();
			else if (arg[i + 1] && arg[i + 1] != ' ')
				throw RPN::ExceptionFormat();
			rpn.manipulatemystack(arg[i]);
		}
		rpn.checkmystack();
	}
	catch (const RPN::ExceptionFormat &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (const RPN::ExceptionNumbers &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch  (const RPN::ExceptionDiv &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch  (const RPN::ExceptionOperators &e)
	{
		std::cerr << e.what() << std::endl;
	}

}