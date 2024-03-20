/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 01:29:39 by jjaen-mo          #+#    #+#             */
/*   Updated: 2024/03/20 02:11:06 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/violence.hpp"

void HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}

void HumanB::attack( void )
{
	std::cout << this->name << " attacks with their ";
	std::cout << this->weapon->getType() << std::endl;
}

HumanB::HumanB(std::string name)
{
	this->name = name;
}

HumanB::~HumanB()
{
	return;
}
