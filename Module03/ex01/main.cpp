/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 07:15:23 by jjaen-mo          #+#    #+#             */
/*   Updated: 2024/04/10 07:49:44 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ScavTrap.hpp"

int main()
{
    ClapTrap claptrap("Clapy");
    ScavTrap scavtrap("Scavy");

    claptrap.attack("Scavy");
    scavtrap.takeDamage(10);
    scavtrap.guardGate();
    scavtrap.attack("Clapy");
    claptrap.takeDamage(20);
    claptrap.beRepaired(15);
    scavtrap.beRepaired(10);
    scavtrap.takeDamage(200);
    return (0);
}