/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: ochetrit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 20:15:20 by ochetrit          #+#    #+#             */
/*   Updated: 2024/12/30 20:15:21 by ochetrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

SCForm::SCForm():AForm("default", 145, 137), target("default")
{
    print("A new ShrubberyCreationForm has been created");
}

SCForm::SCForm(std::string target):AForm("default", 145, 137), target(target)
{
    print("A new ShrubberyCreationForm has been created : " << getName());
}

SCForm::SCForm(const SCForm &other):AForm(other), target(other.target){
    print("Copy construsctor has been called");
}

SCForm::~SCForm(){
    print("ShrubberyCreationForm has been shred");
}


SCForm  &SCForm::operator=(const SCForm &other){
    if (this != &other)
    {
        target = other.target;
    }
}