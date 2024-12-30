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

int main()
{
    Bureaucrat b1;
    Bureaucrat b2("Amiral", 1);
    Bureaucrat b3("Almost fired", 150);
    nl;

    try(b2.DecrementeGrade());
    print(b2);
    try(b2.IncrementeGrade());
    print(b2);
    try(b2.IncrementeGrade());
    print(b2);
    nl;

    print(b3);
    try(b3.IncrementeGrade());
    print(b3);
    try(b3.DecrementeGrade());
    print(b3);
    try(b3.DecrementeGrade());
    print(b3);
    nl;
}