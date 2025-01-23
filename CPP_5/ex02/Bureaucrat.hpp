/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochetrit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 16:08:13 by ochetrit          #+#    #+#             */
/*   Updated: 2024/12/30 16:08:14 by ochetrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"

#define print(x) std::cout << x << std::endl;
#define nl std::cout << std::endl;

#define try(x) try                                          \
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


class AForm;

class Bureaucrat
{
    private:

    const std::string name;
    size_t               grade;
    
    void    setGrade(size_t nb);

    public:

    Bureaucrat();
    Bureaucrat(const Bureaucrat &other);
    Bureaucrat(const std::string name);
    Bureaucrat(std::string name, size_t grade);

    ~Bureaucrat();

    Bureaucrat &operator=(const Bureaucrat &other);

    std::string getName() const;
    size_t      getGrade() const;

    void        IncrementeGrade();
    void        DecrementeGrade();


    class GradeTooLowException: public std::exception{
      public:
      virtual const char *what() const throw();
    };

    class GradeTooHighException: public std::exception{
        public:
        virtual const char *what() const throw();
    };

    void    signAForm(AForm &form);
    void    executeForm(AForm const &form);
};

std::ostream   &operator<<(std::ostream &o, Bureaucrat &obj);

#endif
