/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochetrit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 14:22:08 by ochetrit          #+#    #+#             */
/*   Updated: 2025/02/02 14:22:09 by ochetrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

int main()
{
    std::cout << "Saisssez deux ints:" << std::endl;
    nl;

    std::string input;
    if (!std::getline(std::cin, input))
        return (1);
    int a = atoi(input.c_str());
    if (!std::getline(std::cin, input))
        return (1);
    int b = atoi(input.c_str());
    nl;

    std::cout << "a = " << a << " | b = " << b << std::endl;
    nl;
    std::cout << "Max :" << max(a, b) << std::endl;
    std::cout << "Min :" << min(a, b) << std::endl;
    nl;
    std::cout << "On swap et on a maintenant :" << std::endl;
    swap(&a, &b);
    std::cout << "a = " << a << " | b = " << b << std::endl;
    nl;
    nl;

    std::cout << "Saisssez deux doubles:" << std::endl;
    nl;

    if (!std::getline(std::cin, input))
        return (1);
    double a_f = atof(input.c_str());
    if (!std::getline(std::cin, input))
        return (1);
    double b_f = atof(input.c_str());
    nl;

    std::cout << "a = " << a_f << " | b = " << b_f << std::endl;
    nl;
    std::cout << "Max :" << max(a_f, b_f) << std::endl;
    std::cout << "Min :" << min(a_f, b_f) << std::endl;
    nl;
    std::cout << "On swap et on a maintenant :" << std::endl;
    swap(&a_f, &b_f);
    std::cout << "a = " << a_f << " | b = " << b_f << std::endl;

    nl;
    nl;

    std::cout << "Saisssez deux strings:" << std::endl;
    nl;

    std::string a_s;
    if (!std::getline(std::cin, a_s))
        return (1);
    std::string b_s;
    if (!std::getline(std::cin, b_s))
        return (1);
    nl;

    std::cout << "a = " << a_s << " | b = " << b_s << std::endl;
    nl;
    std::cout << "Max :" << ::max(a_s, b_s) << std::endl;
    std::cout << "Min :" << ::min(a_s, b_s) << std::endl;
    nl;
    std::cout << "On swap et on a maintenant :" << std::endl;
    swap(&a_s, &b_s);
    std::cout << "a = " << a_s << " | b = " << b_s << std::endl;

    nl;
    nl;
}