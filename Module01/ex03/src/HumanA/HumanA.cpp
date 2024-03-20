/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 01:29:47 by jjaen-mo          #+#    #+#             */
/*   Updated: 2024/03/20 02:16:40 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/violence.hpp"

void HumanA::attack( void )
{
	std::cout << this->name << " attacks with their ";
	std::cout << this->weapon.getType() << std::endl;
}

HumanA::HumanA(std::string name, Weapon &weapon) : name(name), weapon(weapon)
{
	return;
}

HumanA::~HumanA()
{
	return ;
}
