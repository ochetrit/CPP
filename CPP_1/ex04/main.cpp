/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochetrit <ochetrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 16:43:46 by ochetrit          #+#    #+#             */
/*   Updated: 2024/11/04 19:15:48 by ochetrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string.h>
#include <fstream>

void	replaceAll(std::string &line, const std::string s1, const std::string s2)
{
	unsigned long pos = 0;
	if (s1.empty())
		return ;
	while ((pos = line.find(s1, pos)) != std::string::npos){
		if (s1.length() == s2.length()){
			for (unsigned long i = 0; i < s1.length(); i++)
				line[pos + i] = s2[i];
		}
		else {
			line = line.substr(0, pos) + s2 + line.substr(pos + s1.length());
		}
		pos += s2.length();
	}
}

int main (int ac, char **av)
{
	if (ac != 4)
	{
		std::cout << "This program needs 3 arguments, try again !" << std::endl;
		return (2);
	}
	std::string file = std::string(av[1]);
	std::ifstream fd(av[1]);
	if (!fd.is_open()){
		std::cerr << "Could not open the file, check the name or the rights of the file" << std::endl;
		return (1);
	}
	std::string newfile1 = file.append(".replace");
	const char *newfile = newfile1.c_str();
	std::ofstream newfd(newfile, std::ios::out | std::ios::trunc);
	if (!fd.is_open()){
		std::cerr << "Could not open the file, check the rights of the file" << std::endl;
		return (1);
	}
	std::string line = std::string();
	std::string s1 = std::string(av[2]);
	std::string s2 = std::string(av[3]);
	while (getline(fd, line))
	{
		replaceAll(line, s1, s2);
		newfd << line << std::endl;
	}
	fd.close();
	newfd.close();
	return (0);
}