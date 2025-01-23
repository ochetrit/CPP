/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochetrit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 20:15:20 by ochetrit          #+#    #+#             */
/*   Updated: 2024/12/30 20:15:21 by ochetrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form():name("default"), _is_signed(false), sign_grade(100), exec_grade(50)
{
    print("Default constructor form called");
}

Form::Form(std::string name, size_t nb_s, size_t nb_ex): name(name), _is_signed(false), sign_grade(nb_s), exec_grade(nb_ex)
{
    if (nb_s < 1 || nb_ex < 1)
        throw Form::GradeTooHighException();
    else if (nb_s > 150 || nb_ex > 150)
        throw Form::GradeTooLowException();
    print(name << " is the new Form");
}

Form::Form(const Form &other):name(other.name), _is_signed(false), sign_grade(100), exec_grade(50){
    print("Copy constructor has been called on " << this->getName());
    *this = other;
}

Form  &Form::operator=(const Form &other){
    return (*this);
}

const char    *Form::GradeTooLowException::what() const throw(){
    return ("Grade too low");
}

const char	*Form::GradeTooHighException::what() const throw(){
	return ("Grade too high");
}

Form::~Form(){
    print(getName() << " has been shred");
}


/// GETTER

std::string Form::getName() const{
    return (name);
}

bool        Form::getIsSigned() const{
    return (_is_signed);
}

size_t      Form::getSignGrade() const{
    return (sign_grade);
}

size_t      Form::getExecGrade() const{
    return (exec_grade);
}

void    Form::signForm(){
    _is_signed = true;
}

void    Form::beSigned(Bureaucrat &bur)
{
    bur.signForm(*this);
}


std::ostream    &operator<<(std::ostream &o, const Form &other)
{
    o << other.getName() << " signed : " << other.getIsSigned() << "\nsign grade : "
     << other.getSignGrade() << "\nExecGrade : " << other.getExecGrade();
     return (o);
}
