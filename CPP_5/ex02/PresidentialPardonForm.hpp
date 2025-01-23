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

#define PPForm PresidentialPardonForm

class PPForm: public AForm
{

    private :

    std::string target;

    public :

///     CONSTRUCTOR     ////

    PPForm();
    PPForm(std::string name, std::string target);
    PPForm(const PPForm &other);

    ~PPForm();

    PPForm  &operator=(const PPForm &other);

    std::string getTarget() const;
    void execute(Bureaucrat const & executor) const;
};

std::ostream    &operator<<(std::ostream &o, const PPForm &other);