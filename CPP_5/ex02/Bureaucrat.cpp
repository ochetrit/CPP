/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochetrit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 16:08:07 by ochetrit          #+#    #+#             */
/*   Updated: 2024/12/30 16:08:08 by ochetrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"
# include "RobotomyRequestForm.hpp"

Bureaucrat::Bureaucrat():name("default"), grade(150){
    print("Default constructor has been called");
}

Bureaucrat::Bureaucrat(const std::string name):name(name), grade(150){
    print("New Bureaucrat has been built and he is called " << name);
}

Bureaucrat::Bureaucrat(std::string name, size_t grade):name(name){
	if (grade > 150){
		throw Bureaucrat::GradeTooLowException();
		setGrade(150);
	}
	else if (grade < 1){
		throw Bureaucrat::GradeTooHighException();
		setGrade(150);
	}
	else
		this->grade = grade;
    print("New Bureaucrat called " << name << ", grade : " << this->getGrade());
}

Bureaucrat::Bureaucrat(const Bureaucrat &other):name(other.name){
    print("Copy constructor has been called on " << this->getName());
    *this = other;
}

Bureaucrat  &Bureaucrat::operator=(const Bureaucrat &other){
    if (this != &other)
        this->grade = other.getGrade();
    return (*this);
}


Bureaucrat::~Bureaucrat(){
    print(name << " just got fired, cy@.");
}

std::string Bureaucrat::getName() const{
    return (this->name);
}

size_t  Bureaucrat::getGrade() const{
    return (this->grade);
}

/// Setter and how to handle exception

void    Bureaucrat::setGrade(size_t nb){
    if (nb > 150)
        throw Bureaucrat::GradeTooLowException();
	else if (nb < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->grade = nb;
}

const char    *Bureaucrat::GradeTooLowException::what() const throw(){
    return ("Grade too low");
}

const char	*Bureaucrat::GradeTooHighException::what() const throw(){
	return ("Grade too high");
}


/// Incremente ///

void	Bureaucrat::IncrementeGrade(){
	if (getGrade() == 1)
		throw Bureaucrat::GradeTooHighException();
	else
	{
		setGrade(getGrade() - 1);
		print(getName() << " just got incremented !");
	}
}

void	Bureaucrat::DecrementeGrade(){
	if (getGrade() == 150)
		throw Bureaucrat::GradeTooLowException();
	else
	{
		setGrade(getGrade() + 1);
		print(getName() << " just got decremented !");
	}
}

void	Bureaucrat::signAForm(AForm &form)
{
	if (!form.getIsSigned() && getGrade() <= form.getSignGrade())
	{
		form.signAForm();
		print(getName() << " signed " << form.getName());
	}
	else if (form.getIsSigned())
	{
		print(getName() << " couldn't sign "<< form.getName() << " because it's already signed");
	}
	else
	{
		print(getName() << " couldn't sign "<< form.getName());
		throw AForm::GradeTooLowException();
	}
}

void	Bureaucrat::executeForm(AForm const &form)
{
		form.execute(*this);
		print(getName() << " executed " << form.getName());
}

/// Overload of <<

std::ostream	&operator<<(std::ostream &o, Bureaucrat &obj){
	o << obj.getName() << ", bureaucrat grade " << obj.getGrade();
	return (o);
}
