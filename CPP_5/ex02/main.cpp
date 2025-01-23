/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochetrit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 16:08:21 by ochetrit          #+#    #+#             */
/*   Updated: 2024/12/30 16:08:21 by ochetrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {

    std::cout << "-------------- ShruberryCreationForm test --------------" << std::endl << std::endl;
    
    AForm *Shruberry = NULL;

    std::cout << std::endl << " ## must have not signed exception ## " << std::endl;
    try {
        Bureaucrat Alice("Alice", 143);
        Shruberry = new ShrubberyCreationForm("shrub", "plant");
        Alice.executeForm(*Shruberry);
        std::cout << "\033[32mForm succesfully signed and executed\033[0m" << std::endl;
    } catch (AForm::Isnotsigned &c) {
        std::cout << "\033[31m" << c.what() << "\033[0m" << std::endl;

    } catch (AForm::GradeTooLowException &c) {
        std::cout << "\033[31m" << c.what() << "\033[0m" << std::endl;
    }

    delete Shruberry;  

    std::cout << std::endl << " ## must have too low exception ## " << std::endl;
    try {
        Bureaucrat Alice("Alice", 143);
        Shruberry = new ShrubberyCreationForm("shrub", "plant");
        Shruberry->beSigned(Alice);
        Alice.executeForm(*Shruberry);
        std::cout << "\033[32mForm succesfully signed and executed\033[0m" << std::endl;
    } catch (AForm::Isnotsigned &c) {
        std::cout << "\033[31m" << c.what() << "\033[0m" << std::endl;

    } catch (AForm::GradeTooLowException &c) {
        std::cout << "\033[31m" << c.what() << "\033[0m" << std::endl;
    }

    delete Shruberry; 

    std::cout << std::endl << " ## must excecute ## " << std::endl;
    try {
        Bureaucrat Alice("Alice", 130);
        Shruberry = new ShrubberyCreationForm("shrub", "plant");
        Shruberry->beSigned(Alice);
        Alice.executeForm(*Shruberry);
        std::cout << "\033[32mForm succesfully signed and executed\033[0m" << std::endl;
    } catch (AForm::Isnotsigned &c) {
        std::cout << "\033[31m" << c.what() << "\033[0m" << std::endl;

    } catch (AForm::GradeTooLowException &c) {
        std::cout << "\033[31m" << c.what() << "\033[0m" << std::endl;
    }

    delete Shruberry; 

    std::cout << " --------------- RobotomyRequestForm tests -------------------" << std::endl << std::endl;

    AForm *Robotomy = NULL;

    std::cout << std::endl << " ## must have not signed exception ## " << std::endl;
    try {
        Bureaucrat Alice("Alice", 71);
        Robotomy = new RobotomyRequestForm("shrub", "human");
        Alice.executeForm(*Robotomy);
        std::cout << "\033[32mForm succesfully signed and executed\033[0m" << std::endl;
    } catch (AForm::Isnotsigned &c) {
        std::cout << "\033[31m" << c.what() << "\033[0m" << std::endl;

    } catch (AForm::GradeTooLowException &c) {
        std::cout << "\033[31m" << c.what() << "\033[0m" << std::endl;
    } catch (RRForm::FailedRobotomy &c){
        std::cout << "\033[31m" << c.what() << "\033[0m" << std::endl;
    }

    delete Robotomy; 

    std::cout << std::endl << " ## must have too low exception ## " << std::endl;
    try {
        Bureaucrat Alice("Alice", 76);
        Robotomy = new RobotomyRequestForm("shrub", "human");
        Robotomy->beSigned(Alice);
        Alice.executeForm(*Robotomy);
        std::cout << "\033[32mForm succesfully signed and executed\033[0m" << std::endl;
    } catch (AForm::Isnotsigned &c) {
        std::cout << "\033[31m" << c.what() << "\033[0m" << std::endl;

    } catch (AForm::GradeTooLowException &c) {
        std::cout << "\033[31m" << c.what() << "\033[0m" << std::endl;
    } catch (RRForm::FailedRobotomy &c){
        std::cout << "\033[31m" << c.what() << "\033[0m" << std::endl;
    }

    delete Robotomy;  

    std::cout << std::endl << " ## must execute## " << std::endl;
    try {
        Bureaucrat Alice("Alice", 1);
        Robotomy = new RobotomyRequestForm("shrub", "human");
        Robotomy->beSigned(Alice);
        Alice.executeForm(*Robotomy);
        std::cout << "\033[32mForm succesfully signed and executed\033[0m" << std::endl;
        std::cout << "Test random Robotomy :" << std::endl;
        for (int i = 0; i < 10; i++) {
            Alice.executeForm(*Robotomy);
        }
    } catch (AForm::Isnotsigned &c) {
        std::cout << "\033[31m" << c.what() << "\033[0m" << std::endl;

    } catch (AForm::GradeTooLowException &c) {
        std::cout << "\033[31m" << c.what() << "\033[0m" << std::endl;
    } catch (RRForm::FailedRobotomy &c){
        std::cout << "\033[31m" << c.what() << "\033[0m" << std::endl;
    } 

    delete Robotomy; 


    std::cout << "----------------------- Presidential Pardon --------------------------" << std::endl << std::endl;
    std::cout<< "# must be not signed" << std::endl;
    AForm *Presidential;

    try {
        Bureaucrat Alice("ALice", 20);
        Presidential = new PresidentialPardonForm("Bobby", "convict");
        Alice.executeForm(*Presidential);
        std::cout << "\033[32mForm succesfully signed and executed\033[0m" << std::endl;
    } catch (AForm::Isnotsigned &c) {
        std::cout << "\033[31m" << c.what() << "\033[0m" << std::endl;

    } catch (AForm::GradeTooLowException &c) {
        std::cout << "\033[31m" << c.what() << "\033[0m" << std::endl;
    }

    delete Presidential;


    std::cout<< "# must be too low to sign" << std::endl;
    try {
        Bureaucrat Alice("ALice", 26);
        Presidential = new PresidentialPardonForm("Bobby", "convict");
        Presidential->beSigned(Alice);
        Alice.executeForm(*Presidential);
        std::cout << "\033[32mForm succesfully signed and executed\033[0m" << std::endl;

    } catch (AForm::Isnotsigned &c) {
        std::cout << "\033[31m" << c.what() << "\033[0m" << std::endl;

    } catch (AForm::GradeTooLowException &c) {
        std::cout << "\033[31m" << c.what() << "\033[0m" << std::endl;
    }

    delete Presidential;

    std::cout<< "# must be too low to execute" << std::endl;
    try {
        Bureaucrat Alice("ALice", 20);
        Presidential = new PresidentialPardonForm("Bobby", "convict");
        Presidential->beSigned(Alice);
        Alice.executeForm(*Presidential);
        std::cout << "\033[32mForm succesfully signed and executed\033[0m" << std::endl;

    } catch (AForm::Isnotsigned &c) {
        std::cout << "\033[31m" << c.what() << "\033[0m" << std::endl;

    } catch (AForm::GradeTooLowException &c) {
        std::cout << "\033[31m" << c.what() << "\033[0m" << std::endl;
    }


    delete Presidential;

    std::cout<< "# must be signed ans executed" << std::endl;
    try {
        Bureaucrat Alice("ALice", 4);
        Presidential = new PresidentialPardonForm("Bobby", "convict");
        Presidential->beSigned(Alice);
        Alice.executeForm(*Presidential);
        std::cout << "\033[32mForm succesfully signed and executed\033[0m" << std::endl;
    } catch (AForm::Isnotsigned &c) {
        std::cout << "\033[31m" << c.what() << "\033[0m" << std::endl;

    } catch (AForm::GradeTooLowException &c) {
        std::cout << "\033[31m" << c.what() << "\033[0m" << std::endl;
    }

    delete Presidential;
}
