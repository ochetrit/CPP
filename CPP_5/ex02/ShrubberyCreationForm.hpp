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
#include <fstream>
#include "AForm.hpp"

#define SCForm ShrubberyCreationForm

class SCForm: public AForm
{

    private :

    std::string target;

    public :

///     CONSTRUCTOR     ////

    SCForm();
    SCForm(std::string name, std::string target);
    SCForm(const SCForm &other);

    ~SCForm();

    SCForm  &operator=(const SCForm &other);

    std::string getTarget() const;
    void execute(Bureaucrat const & executor) const;
};

std::ostream    &operator<<(std::ostream &o, const SCForm &other);