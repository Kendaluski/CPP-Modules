/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 08:31:03 by jjaen-mo          #+#    #+#             */
/*   Updated: 2024/04/29 18:22:27 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Animal.hpp"
 
Animal::Animal()
{
    std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const Animal &animal)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = animal;
}

Animal::~Animal()
{
    std::cout << "Animal destructor called" << std::endl;
}

Animal & Animal::operator = (const Animal &animal)
{
    std::cout << "Copy operator called" << std::endl;
    this->type = animal.type;
    return (*this);
}

std::string Animal::getType() const
{
    return (this->type);
}

void Animal::makeSound() const
{
    if(this->type.empty())
        return;
}

void Animal::setType(std::string type)
{
    this->type = type;
}

std::ostream &operator<<(std::ostream &out, const Animal &animal)
{
    out << "Type: " << animal.getType();
    return (out);
}