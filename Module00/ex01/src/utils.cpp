/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 19:11:30 by jjaen-mo          #+#    #+#             */
/*   Updated: 2024/03/12 20:29:37 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/phonebook.hpp"

void ft_printer(std::string str)
{
	if(str.length() < 10)
	{
		for(unsigned long j = 0; j < 10 - str.length(); j++)
			std::cout << " ";
	}
	for (unsigned long j = 0; j < 10; j++)
	{
		if(j == 9 && str.length() >= 10)
			std::cout << ".";
		else if (j < str.length())
			std::cout << str[j];
	}
}

void ft_searcher(std::string str, Phonebook *phonebook)
{
	int i;

	i = std::stoi(str);
	if (i < 0 || i > 7 || phonebook->contacts[i].first_name[0] == '\0')
	{
		std::cout << "Invalid index" << std::endl;
		return ;
	}
	std::cout << "First Name: " << phonebook->contacts[i].first_name << std::endl;
	std::cout << "Last Name: " << phonebook->contacts[i].last_name << std::endl;
	std::cout << "Nickname: " << phonebook->contacts[i].nickname << std::endl;
	std::cout << "Phone Number: " << phonebook->contacts[i].phone_number << std::endl;
	std::cout << "Darkest Secret: " << phonebook->contacts[i].darkest_secret << std::endl;
}

int ft_strncmp(const char *s1, const char *s2, int j)
{
	int i = 0;
	
	while(s1[i] && s2[i] && i < j)
	{
		if(s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	if(!s1[i] && i < j)
		return (s2[i]);
	return (0);
}