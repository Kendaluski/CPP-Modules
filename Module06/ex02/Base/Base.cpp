/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 08:59:03 by jjaen-mo          #+#    #+#             */
/*   Updated: 2024/10/31 09:21:08 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base::~Base()
{
	std::cout << RED << "Base destructor called" << std::endl;
}

Base * generate(void)
{
	int n;

	std::srand(std::time(0));
	n = std::rand() % 3;
	if (n == 0)
	{
		std::cout << GREEN << "A class generated" << RESET << std::endl;
		return (new A);
	}
	else if (n == 1)
	{
		std::cout << GREEN << "B class generated" << RESET << std::endl;
		return (new B);
	}
	else
	{
		std::cout << GREEN << "C class generated" << RESET << std::endl;
		return (new C);
	}
}

void identify(Base *p)
{
	if(dynamic_cast<A *>(p))
		std::cout << MAGENTA << "A" << RESET << std::endl;
	else if(dynamic_cast<B *>(p))
		std::cout << MAGENTA << "B" << RESET << std::endl;
	else if(dynamic_cast<C *>(p))
		std::cout << MAGENTA << "C" << RESET << std::endl;
	else
		std::cout << RED << "Unknown class" << RESET << std::endl;
}

void identify(Base& p)
{
	try {
		A &a = dynamic_cast<A &>(p);
		std::cout << MAGENTA << "A" << RESET << std::endl;
		(void)a;
	} catch (std::bad_cast&) {}
	
	try {
		B &b = dynamic_cast<B &>(p);
		std::cout << MAGENTA << "B" << RESET << std::endl;
		(void)b;
	} catch (std::bad_cast&) {}

	try {
		C &c = dynamic_cast<C &>(p);
		std::cout << MAGENTA << "C" << RESET << std::endl;
		(void)c;
	} catch (std::bad_cast&) {}
}
