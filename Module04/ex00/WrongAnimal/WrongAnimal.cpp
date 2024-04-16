/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 04:50:01 by jjaen-mo          #+#    #+#             */
/*   Updated: 2024/04/15 05:21:02 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/WrongAnimal.hpp"
 
WrongAnimal::WrongAnimal()
{
    std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &wronganimal)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = wronganimal;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal destructor called" << std::endl;
}

std::string WrongAnimal::getType() const
{
    return (this->type);
}

void WrongAnimal::setType(std::string type)
{
    this->type = type;
}

void WrongAnimal::makeSound() const
{
    std::cout << "WrongAnimal sound" << std::endl;
}

WrongAnimal & WrongAnimal::operator = (const WrongAnimal &wronganimal)
{
    std::cout << "Copy operator called" << std::endl;
    this->type = wronganimal.type;
    return (*this);
}
 
std::ostream &operator<<(std::ostream &out, const WrongAnimal &wronganimal)
{
    out << wronganimal.getType();
    return (out);
}