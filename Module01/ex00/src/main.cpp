/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 18:51:12 by jjaen-mo          #+#    #+#             */
/*   Updated: 2024/03/19 19:25:12 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie/Zombie.hpp"

int main(void)
{
	Zombie *zombie = newZombie("Eustaquio");
	zombie->announce();
	randomChump("Habichuela");
	delete zombie;
}