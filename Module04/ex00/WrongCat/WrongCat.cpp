/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 04:49:58 by jjaen-mo          #+#    #+#             */
/*   Updated: 2024/04/15 05:17:25 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/WrongCat.hpp"
 
WrongCat::WrongCat() : WrongAnimal()
{
    std::cout << "WrongCat constructor called" << std::endl;
    this->type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &wrongcat) : WrongAnimal()
{
    std::cout << "Copy constructor called" << std::endl;
    *this = wrongcat;
}

void WrongCat::makeSound() const
{
    std::cout << "WrongCat sound" << std::endl;
}

WrongCat::~WrongCat()
{
    std::cout << "Wrong Cat destructor called" << std::endl;
}

WrongCat & WrongCat::operator = (const WrongCat &wrongcat)
{
    std::cout << "Copy operator called" << std::endl;
    this->type = wrongcat.type;
    return (*this);
}
 
std::ostream &operator<<(std::ostream &out, const WrongCat &wrongcat)
{
    out << wrongcat.getType();
    return (out);
}