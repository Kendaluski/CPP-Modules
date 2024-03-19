/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 19:32:05 by jjaen-mo          #+#    #+#             */
/*   Updated: 2024/03/12 19:12:18 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/phonebook.hpp"

int	main(void)
{
	char buffer[512];
	int index = 0;
	Phonebook phonebook;

	std::cout << "Welcome to the phonebook, please enter a command: ";
	std::cin >> buffer;
	while(ft_strncmp(buffer, "EXIT", 4))
	{
		if(!ft_strncmp(buffer,"ADD", 3))
		{
			if(index >= 8)
				index = 0;
			phonebook.contacts[index].Create();
			index++;
			std::cout << "Welcome to the phonebook, please enter a command: ";
			std::cin >> buffer;
		}
		else if(!ft_strncmp(buffer,"SEARCH", 6))
		{
			phonebook.Search();
			std::cout << "Welcome to the phonebook, please enter a command: ";
			std::cin >> buffer;
		}
		else
		{
			std::cout << "Invalid command, please enter ADD/SEARCH/EXIT: ";
			std::cin >> buffer;
		}
	}
	return (0);
}
