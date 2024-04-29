/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 07:15:23 by jjaen-mo          #+#    #+#             */
/*   Updated: 2024/04/10 08:10:11 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/FragTrap.hpp"

int main()
{
    ClapTrap claptrap("Clapy");
    ScavTrap scavtrap("Scavy");
    FragTrap fragtrap("Fragy");

    claptrap.attack("Scavy");
    scavtrap.takeDamage(10);
    scavtrap.guardGate();
    scavtrap.attack("Fragy");
    fragtrap.takeDamage(20);
    fragtrap.beRepaired(15);
    fragtrap.attack("Scavy");
    scavtrap.takeDamage(30);
    fragtrap.highFivesGuys();
    return (0);
}