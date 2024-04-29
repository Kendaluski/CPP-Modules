/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 06:03:15 by jjaen-mo          #+#    #+#             */
/*   Updated: 2024/04/29 18:24:06 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AMateria.hpp"
 
AMateria::AMateria(std::string const & type)
{
    std::cout << "Materia constructor called" << std::endl;
    this->_type = type;
}

AMateria::AMateria(const AMateria &amateria)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = amateria;
}

AMateria::~AMateria()
{
    std::cout << "AMateria destructor called" << std::endl;
}

std::string const & AMateria::getType() const
{
    return (this->_type);
}

void AMateria::use(ICharacter &target)
{
    std::cout << " * uses some materia on " << target.getName() << std::endl;
}

AMateria & AMateria::operator = (const AMateria &amateria)
{
    std::cout << "Copy operator called" << std::endl;
    if(this == &amateria)
        return (*this);
    return (*this);
}
