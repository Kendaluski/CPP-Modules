/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 18:51:12 by jjaen-mo          #+#    #+#             */
/*   Updated: 2024/03/19 22:19:57 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie/Zombie.hpp"

int main(void)
{
	int N;

	std::cout << "Enter the number of zombies: ";
	std::cin >> N;
	
	Zombie *zombie = zombieHorde(N, "Eustaquio");
	
	for (int i = 0; i < N; i++)
		zombie[i].announce();

	for (int i = 0; i < N; i++)
		zombie[i].~Zombie();
}
