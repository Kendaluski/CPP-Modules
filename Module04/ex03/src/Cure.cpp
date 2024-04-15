/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 06:10:39 by jjaen-mo          #+#    #+#             */
/*   Updated: 2024/04/15 06:32:25 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cure.hpp"
 
Cure::Cure()
{
    std::cout << "Default constructor called on " << this << std::endl;
}

Cure::Cure(const Cure &cure)
{
    std::cout << "Copy constructor called on " << this << std::endl;
}

Cure::~Cure()
{
    std::cout << "Destructor called on " << this << std::endl;
}

Cure *Cure::clone() const
{
    Cure *cure = new Cure(*this);
    return (cure);
}

void Cure::use(ICharacter &target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

Cure & Cure::operator = (const Cure &cure)
{
    std::cout << "Copy operator called on " << this << std::endl;
}
 
std::ostream &operator<<(std::ostream &out, const Cure &cure)
{
    out << "Cure [" << "" << "]";
    return (out);
}