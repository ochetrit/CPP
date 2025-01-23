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

#ifndef AFORM_HPP
# define AFORM_HPP

# include <string>
# include <iostream>
# include <stdlib.h>
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

class AForm
{
    private:

    const std::string name;
    bool _is_signed;
    const size_t  sign_grade;
    const size_t  exec_grade;


    public:

    AForm();
    AForm(const AForm &other);
    AForm(std::string name, size_t nb_s, size_t nb_ex);

    virtual ~AForm();

    AForm &operator=(const AForm &other);

    std::string getName() const;
    bool        getIsSigned() const;
    size_t      getSignGrade() const;
    size_t      getExecGrade() const;

    virtual void        signAForm();

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

    class Isnotsigned: public std::exception
    {
        public :
        virtual const char *what() const throw();
    };

    virtual void execute(Bureaucrat const & executor) const = 0;
    void    beSigned(Bureaucrat &bur);
    
};

std::ostream    &operator<<(std::ostream &o, const AForm &other);

#endif