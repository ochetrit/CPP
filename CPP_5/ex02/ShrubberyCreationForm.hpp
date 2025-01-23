/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochetrit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 20:15:16 by ochetrit          #+#    #+#             */
/*   Updated: 2024/12/30 20:15:17 by ochetrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include "AForm.hpp"

#define SCForm ShrubberyCreationForm

class SCForm: private AForm
{

    private :

    std::string target;

    public :

///     CONSTRUCTOR     ////

    SCForm();
    SCForm(std::string target);
    SCForm(const SCForm &other);

    ~SCForm();

    SCForm  &operator=(const SCForm &other);
};