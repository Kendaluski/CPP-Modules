/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 08:45:32 by jjaen-mo          #+#    #+#             */
/*   Updated: 2024/04/15 05:36:01 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Dog.hpp"
 
Dog::Dog() : Animal()
{
    std::cout << "Dog default constructor called" << std::endl;
    type = "Dog";
    this->brain = new Brain();
}

Dog::Dog(const Dog &dog) : Animal()
{
    std::cout << "Copy constructor called"<< std::endl;
    *this = dog;
}

Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;
}

Dog & Dog::operator = (const Dog &dog)
{
    std::cout << "Copy operator called" << std::endl;
    this->type = dog.type;
    return (*this);
}

void Dog::makeSound() const
{
    std::cout << "Guau Guau" << std::endl;
}

std::ostream &operator<<(std::ostream &out, const Dog &dog)
{
    out << "Type: " << dog.getType();
    return (out);
}