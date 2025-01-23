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

#include "RobotomyRequestForm.hpp"

RRForm::RRForm():AForm("default", 72, 45), target("default")
{
    print("A new RobotomyRequestForm has been created");
}

RRForm::RRForm(std::string name, std::string target):AForm(name, 72, 45), target(target)
{
    print("A new RobotomyRequestForm has been created : " << getName());
}

RRForm::RRForm(const RRForm &other):AForm(other), target(other.target){
    print("Copy construsctor has been called");
}

RRForm::~RRForm(){
    print(getName() << " has been shred");
}


RRForm  &RRForm::operator=(const RRForm &other){
    if (this != &other)
        target = other.target;
    return (*this);
}

std::string     RRForm::getTarget() const{
    return (target);
}

void    RRForm::execute(Bureaucrat const & executor) const
{
    if (getIsSigned() == false)
        throw AForm::Isnotsigned();
    else if (executor.getGrade() > getExecGrade())
        throw AForm::GradeTooLowException();

    int success = std::rand() % 2;
    for (int i = 0; i < 3; i++)
        print("BRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR");
    if (success){
        print(getTarget() << " has been robotomized successfully");}
    else
        throw RRForm::FailedRobotomy();
}

const char  *RRForm::FailedRobotomy::what() const throw(){
    return ("Robotomy failed... unlucky !");
}


std::ostream    &operator<<(std::ostream &o, const RRForm &other)
{
    o << other.getName() << " signed : " << other.getIsSigned() << "\nsign grade : "
     << other.getSignGrade() << "\nExecGrade : " << other.getExecGrade() << "\ntarget : " << other.getTarget();
    return (o);
}