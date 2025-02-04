/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochetrit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:37:07 by ochetrit          #+#    #+#             */
/*   Updated: 2025/02/04 17:37:07 by ochetrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <map>
#include <iomanip>

#define print(x) std::cout << x << std::endl
#define nl std::cout << std::endl


class BitcoinExchange
{
    private:
    std::map<std::string, double>  _data;
    std::ifstream _fd;
    std::string   _filename;

    public:
    BitcoinExchange();
    BitcoinExchange(std::string filename);
    BitcoinExchange(const BitcoinExchange &other);

    BitcoinExchange &operator=(const BitcoinExchange &other);

    ~BitcoinExchange();

    void    fill_map();
    void    print_map();

    class   ExceptionDate: public std::exception
    {
        public :

        virtual const char  *what() const throw();
    };

    class   ExceptionValue: public std::exception
    {
        public :

        virtual const char  *what() const throw();
    };

    class   ExceptionOpen: public std::exception
    {
        public :

        virtual const char  *what() const throw();
    };

};

