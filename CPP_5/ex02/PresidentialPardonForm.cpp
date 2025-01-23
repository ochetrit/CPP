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

#include "PresidentialPardonForm.hpp"

PPForm::PPForm():AForm("default", 25, 5), target("default")
{
    print("A new PresidentialPardonForm has been created");
}

PPForm::PPForm(std::string name, std::string target):AForm(name, 25, 5), target(target)
{
    print("A new PresidentialPardonForm has been created : " << getName());
}

PPForm::PPForm(const PPForm &other):AForm(other), target(other.target){
    print("Copy construsctor has been called");
}

PPForm::~PPForm(){
    print(getName() << " has been shred");
}


PPForm  &PPForm::operator=(const PPForm &other){
    if (this != &other)
        target = other.target;
    return (*this);
}

std::string     PPForm::getTarget() const{
    return (target);
}

void    PPForm::execute(Bureaucrat const & executor) const
{
    if (getIsSigned() == false)
        throw AForm::Isnotsigned();
    else if (executor.getGrade() > getExecGrade())
        throw AForm::GradeTooLowException();

    print(getTarget() << " has been pardoned by Zaphod Beeblebrox.");
}

std::ostream    &operator<<(std::ostream &o, const PPForm &other)
{
    o << other.getName() << " signed : " << other.getIsSigned() << "\nsign grade : "
     << other.getSignGrade() << "\nExecGrade : " << other.getExecGrade() << "\ntarget : " << other.getTarget();
    return (o);
}