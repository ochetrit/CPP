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

#define RRForm RobotomyRequestForm

class RRForm: public AForm
{

    private :

    std::string target;

    public :

///     CONSTRUCTOR     ////

    RRForm();
    RRForm(std::string name, std::string target);
    RRForm(const RRForm &other);

    ~RRForm();

    RRForm  &operator=(const RRForm &other);

    std::string getTarget() const;
    void execute(Bureaucrat const & executor) const;

    class FailedRobotomy: public std::exception
    {
        public :
        virtual const char *what() const throw();
    };

};

std::ostream    &operator<<(std::ostream &o, const RRForm &other);