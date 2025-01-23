/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochetrit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 20:15:16 by ochetrit          #+#    #+#             */
/*   Updated: 2024/12/30 20:15:17 by ochetrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <iostream>
# include "Bureaucrat.hpp"

#define try2(x) try                                          \
                {                                           \
                    x;                                       \
                }                                           \
                catch(Bureaucrat::GradeTooHighException &e)\
                {                                           \
                    std::cerr << e.what() << std::endl;     \
                }                                           \
                catch(Bureaucrat::GradeTooLowException &e)  \
                {                                           \
                    std::cerr << e.what() << std::endl;     \
                }                                           \

class Bureaucrat;

class Form
{
    private:

    const std::string name;
    bool _is_signed;
    const size_t  sign_grade;
    const size_t  exec_grade;


    public:

    Form();
    Form(const Form &other);
    Form(std::string name, size_t nb_s, size_t nb_ex);

    ~Form();

    Form &operator=(const Form &other);

    std::string getName() const;
    bool        getIsSigned() const;
    size_t      getSignGrade() const;
    size_t      getExecGrade() const;

    void        signForm();

    class GradeTooLowException: public std::exception
    {
        public :
        virtual const char *what() const throw();
    };

    class GradeTooHighException: public std::exception
    {
        public :
        virtual const char *what() const throw();
    };


    void    beSigned(Bureaucrat &bur);
    
};

std::ostream    &operator<<(std::ostream &o, const Form &other);

#endif