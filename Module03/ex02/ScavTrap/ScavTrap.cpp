/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 07:25:54 by jjaen-mo          #+#    #+#             */
/*   Updated: 2024/04/10 08:10:57 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScavTrap.hpp"
 
ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    std::cout << "Scavtrap constructor called with name: " << name << std::endl;
    _hitpoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << _name << " have entered in Gate keeper mode" << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "Scavtrap destructor called with name: " << _name << std::endl;
}
