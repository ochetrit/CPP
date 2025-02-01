/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochetrit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:39:50 by ochetrit          #+#    #+#             */
/*   Updated: 2025/02/01 15:39:51 by ochetrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer(){
	print("Default constructor has been called.");
}

Serializer::Serializer(const Serializer &other){
	print("Copy constructor has been called.");
	*this = other;
}

Serializer	&Serializer::operator=(const Serializer &other){
	(void)other;
	return (*this);
}

Serializer::~Serializer(){
	print("Destructor has been called");
}

uintptr_t   Serializer::serialize(Data* ptr){
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw){
    return reinterpret_cast<Data *>(raw);
}