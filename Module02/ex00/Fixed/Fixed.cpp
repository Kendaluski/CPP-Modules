/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 11:22:13 by jjaen-mo          #+#    #+#             */
/*   Updated: 2024/04/09 08:27:22 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"

int Fixed::getRawBits(void) const
{
   std::cout << "getRawBits member function called" << std::endl;
   return (_value);
}

void Fixed::setRawBits(int const raw)
{
   std::cout << "setRawBits member function called" << std::endl;
   _value = raw;
}

Fixed::Fixed()
{
   std::cout << "Default constructor called " << std::endl;
   _value = 0;
}
 
Fixed::Fixed(const Fixed &fixed)
{
   _value = fixed.getRawBits();
   std::cout << "Copy constructor called" << std::endl;
}
 
Fixed::~Fixed()
{
   std::cout << "Destructor called" << std::endl;
}
 
Fixed & Fixed::operator = (const Fixed &fixed)
{
   std::cout << "Copy operator called" << std::endl;
   if(this != &fixed)
      _value = fixed.getRawBits();
   return (*this);
}
