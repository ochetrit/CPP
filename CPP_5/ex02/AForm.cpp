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

#include "AForm.hpp"

AForm::AForm():name("default"), _is_signed(false), sign_grade(100), exec_grade(50)
{
    print("Default constructor Aform called");
}

AForm::AForm(std::string name, size_t nb_s, size_t nb_ex): name(name), _is_signed(false), sign_grade(nb_s), exec_grade(nb_ex)
{
    if (nb_s < 1 || nb_ex < 1)
        throw AForm::GradeTooHighException();
    else if (nb_s > 150 || nb_ex > 150)
        throw AForm::GradeTooLowException();
    print(name << " is the new AForm");
}

AForm::AForm(const AForm &other):name(other.name), _is_signed(false), sign_grade(100), exec_grade(50){
    print("Copy constructor has been called on " << this->getName());
    *this = other;
}

AForm  &AForm::operator=(const AForm &other){
    (void)other;
    return (*this);
}

const char    *AForm::GradeTooLowException::what() const throw(){
    return ("Grade too low");
}

const char	*AForm::GradeTooHighException::what() const throw(){
	return ("Grade too high");
}

const char  *AForm::Isnotsigned::what() const throw(){
    return ("This form is not signed and can't be executed...");
}

AForm::~AForm(){
    print(getName() << " has been shred");
}



/// GETTER

std::string AForm::getName() const{
    return (name);
}

bool        AForm::getIsSigned() const{
    return (_is_signed);
}

size_t      AForm::getSignGrade() const{
    return (sign_grade);
}

size_t      AForm::getExecGrade() const{
    return (exec_grade);
}

void    AForm::signAForm(){
    _is_signed = true;
}

void    AForm::beSigned(Bureaucrat &bur)
{
    bur.signAForm(*this);
}


std::ostream    &operator<<(std::ostream &o, const AForm &other)
{
    o << other.getName() << " signed : " << other.getIsSigned() << "\nsign grade : "
     << other.getSignGrade() << "\nExecGrade : " << other.getExecGrade();
     return (o);
}
