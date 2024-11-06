/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 07:53:04 by jjaen-mo          #+#    #+#             */
/*   Updated: 2024/11/05 17:35:09 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
 
Serializer::Serializer()
{
	std::cout << GREEN << "Serializer default constructor called" << RESET << std::endl;
}

Serializer::Serializer(const Serializer &Serializer)
{
	std::cout << "Serializer copy constructor called" << std::endl;
	this->operator=(Serializer);
}

Serializer::~Serializer()
{
	std::cout << ORANGE << "Serializer destructor called" << RESET << std::endl;
}

Serializer & Serializer::operator = (const Serializer &Serializer)
{
	std::cout << "Serialier copy operator called" << std::endl;
	if(this == &Serializer)
		return (*this);
	this->Serializer::operator=(Serializer);
	return (*this);
}

unsigned long Serializer::serialize(Data *ptr)
{
	return reinterpret_cast<unsigned long>(ptr);
}

Data *Serializer::deserialize(unsigned long raw)
{
	return reinterpret_cast<Data *>(raw);
}

std::ostream &operator<<(std::ostream &out, const Serializer &Serializer)
{
	out << "Serializer [" << &Serializer << "]";
	return (out);
}