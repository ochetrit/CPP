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

SCForm::SCForm(std::string name, std::string target):AForm(name, 145, 137), target(target)
{
    print("A new ShrubberyCreationForm has been created : " << getName());
}

SCForm::SCForm(const SCForm &other):AForm(other), target(other.target){
    print("Copy construsctor has been called");
}

SCForm::~SCForm(){
    print(getName() << " has been shred");
}


SCForm  &SCForm::operator=(const SCForm &other){
    if (this != &other)
        target = other.target;
    return (*this);
}

std::string     SCForm::getTarget() const{
    return (target);
}

void    SCForm::execute(Bureaucrat const & executor) const
{
    if (getIsSigned() == false)
        throw AForm::Isnotsigned();
    else if (executor.getGrade() > getExecGrade())
        throw AForm::GradeTooLowException();

    std::ofstream outfile (this->getTarget().append("_shrubbery").c_str());

		for (int i = 0; i < 5; i++)
		{
			outfile <<
			"         v" << std::endl <<
			"        >X<" << std::endl <<
			"         A" << std::endl <<
			"        d$b" << std::endl <<
			"      .d\\$$b." << std::endl <<
			"    .d$i$$\\$$b." << std::endl <<
			"       d$$@b" << std::endl <<
			"      d\\$$$ib" << std::endl <<
			"    .d$$$\\$$$b" << std::endl <<
			"  .d$$@$$$$\\$$ib." << std::endl <<
			"      d$$i$$b" << std::endl <<
			"     d\\$$$$@$b" << std::endl <<
			"  .d$@$$\\$$$$$@b." << std::endl <<
			".d$$$$i$$$\\$$$$$$b." << std::endl <<
			"        ###" << std::endl <<
			"        ###" << std::endl <<
			"        ###" << std::endl <<
		std::endl;
		}
		outfile.close();
}

std::ostream    &operator<<(std::ostream &o, const SCForm &other)
{
    o << other.getName() << " signed : " << other.getIsSigned() << "\nsign grade : "
     << other.getSignGrade() << "\nExecGrade : " << other.getExecGrade() << "\ntarget : " << other.getTarget();
	return (o);
}