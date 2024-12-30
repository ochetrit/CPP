/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochetrit <ochetrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:50:05 by ochetrit          #+#    #+#             */
/*   Updated: 2024/11/26 18:35:09 by ochetrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP
# include <string>
# include <iostream>

class Brain
{
	private:
	std::string _ideas[100];

	public:
	Brain(void);
	Brain(const Brain &other);
	
	void	newIdea(int i, const std::string newIdea);
	void	obssessedBrain(const std::string idea);
	
	std::string	*Thoughts(void);
	std::string oneThought(int i);
	//void	copyideas
	
	~Brain(void);

	Brain &operator=(const Brain &other);
};

#endif
