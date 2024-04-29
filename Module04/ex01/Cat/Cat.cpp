/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 08:39:37 by jjaen-mo          #+#    #+#             */
/*   Updated: 2024/04/29 18:15:57 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cat.hpp"
 
Cat::Cat() : Animal()
{
    std::cout << "Cat constructor called" << std::endl;
    type = "Cat";
    this->brain = new Brain();
}

Cat::Cat(const Cat &cat) : Animal()
{
    std::cout << "Copy constructor called" << std::endl;
    *this = cat;
}

Cat::~Cat()
{
    std::cout << "Cat destructor called" << std::endl;
    delete this->brain;
}

Cat & Cat::operator = (const Cat &cat)
{
    std::cout << "Copy operator called" << std::endl;
    this->type = cat.type;
    return (*this);
}
 
std::ostream &operator<<(std::ostream &out, const Cat &cat)
{
    out << "Type: " << cat.getType();
    return (out);
}

void Cat::makeSound() const
{
    std::cout << "Miau Miau" << std::endl;
}