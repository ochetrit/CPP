/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochetrit <ochetrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:49:55 by ochetrit          #+#    #+#             */
/*   Updated: 2024/11/26 18:35:35 by ochetrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Brain.hpp"

Brain::Brain(void):_ideas()
{
	for (int i = 0; i < 33; i++)
		_ideas[i] = "EAT";
	for (int i = 33; i < 66; i++)	
		_ideas[i] = "SLEEP";
	for (int i = 66; i < 99; i++)
		_ideas[i] = "DRINK";
	_ideas[99] = "Do I have a soul ?";
	std::cout  << "New brain" << std::endl;
}


Brain::Brain(const Brain &other):_ideas()
{
	std::cout << "Copy Brain" << std::endl;
	*this = other;
}

Brain::~Brain(void)
{
	std::cout << "BRAIN K.O." << std::endl;
}

Brain &Brain::operator=(const Brain &other)
{
	if (this != &other)
	{
		for (int i = 0; i < 99; i++)
			this->_ideas[i] = other._ideas[i];
	}
	return (*this);
}

void	Brain::newIdea(int i, const std::string newIdea)
{
	_ideas[i] = newIdea;
}

void	Brain::obssessedBrain(const std::string idea)
{
	for (int i = 0; i < 100; i++)
		_ideas[i] = idea;
}

std::string	*Brain::Thoughts(void)
{
	return _ideas;
}

std::string Brain::oneThought(int i)
{
	return _ideas[i];
}