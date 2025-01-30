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

std::string trim_zeros(const std::string &str) {
    if (str.empty()) return "0";

    std::string result = str;
    bool is_negative = (result[0] == '-');
    bool is_positive = (result[0] == '+');

    size_t start = (is_negative || is_positive) ? 1 : 0;
    size_t first_nonzero = result.find_first_not_of('0', start);

    if (first_nonzero == std::string::npos) return "0";

    result = result.substr(0, start) + result.substr(first_nonzero);

	if (result[0] == '.') {
        result.insert(0, "0");
    }
    if ((is_negative || is_positive) && result[1] == '.') {
        result.insert(1, "0");
    }

    size_t dot_pos = result.find('.');
    if (dot_pos != std::string::npos) {
        size_t last_nonzero = result.find_last_not_of('0');
		
		 if (last_nonzero == dot_pos) {
            result.erase(last_nonzero + 2);
        } else {
            result.erase(last_nonzero + 1);
        }
    }
	
    return result;
}


int main(int ac, char **av)
{
	if (ac != 2)
	{
		print("Error, I need one argument");
		return (1);
	}
	std::string arg = av[1];
	arg = trim_zeros(arg);
	ScalarConverter::convert_type(arg);
	return (0);
}
