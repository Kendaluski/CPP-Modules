/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 06:10:56 by jjaen-mo          #+#    #+#             */
/*   Updated: 2024/04/15 06:33:51 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Ice.hpp"
 
Ice::Ice() : AMateria("ice")
{
    std::cout << "Ice constructor called" << std::endl;
}

Ice::Ice(const Ice &ice) : AMateria(ice)
{
    std::cout << "Copy constructor called" << std::endl;
}

Ice::~Ice()
{
    std::cout << "Ice destructor called" << std::endl;
}

Ice *Ice::clone() const
{
    Ice *ice = new Ice(*this);
    return (ice);
}

void Ice::use(ICharacter &target)
{
    std::cout << " * shoots an ice bolt at " << target.getName() << std::endl;
}

Ice & Ice::operator = (const Ice &ice)
{
    std::cout << "Copy operator called" << std::endl;
}
 
std::ostream &operator<<(std::ostream &out, const Ice &ice)
{
    out << "Ice [" << "" << "]";
    return (out);
}