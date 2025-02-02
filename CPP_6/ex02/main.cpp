/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochetrit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 16:32:42 by ochetrit          #+#    #+#             */
/*   Updated: 2025/02/01 16:32:43 by ochetrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base    *generate()
{
    std::srand(clock());
    int r = std::rand();

    if (r % 3 == 0)
        return (new A);
    else if (r % 3 == 1)
        return (new B);
    else
        return (new C);
}

void identify(Base *p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else
        std::cerr << "Is this else can be usefull?" << std::endl;
}

static void identify(Base &Test, size_t i)
{
    std::string classes[] = {"Class A", "Class B", "Class C"}; 
	void *foo = NULL;
	Base &unused = (Base &)foo;
	try
	{
		if (i == 0)
			unused = dynamic_cast<A &>(Test);
		else if (i == 1)
			unused = dynamic_cast<B &>(Test);
		else if (i == 2)
			unused = dynamic_cast<C &>(Test);
		else
			std::cout << "unknow type" << std::endl;
	}
	catch (std::exception &e)
	{
		identify(Test, ++i);
		return;
	}
	std::cout << classes[i] << " is the identified type" << std::endl;
}

int	main()
{

    for (int i = 0; i < 10; i++)
    {
        Base *p = generate();
        std::cout << "Identify by pointer: ";
        identify(p);
        std::cout << "Identify by reference: ";
        identify(*p, 0);
        delete p;
        std::cout << "-------------------------------------\n\n\n" << std::endl;
    }
    std::cout << "--------------------------------------------" << std::endl;

    return (0);
}
