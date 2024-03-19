/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   class_fts.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 20:03:04 by jjaen-mo          #+#    #+#             */
/*   Updated: 2024/03/12 19:54:42 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/phonebook.hpp"

Contact::Contact(void)
{
	return ;
}

void Contact::Create(void)
{
	std::cout << "First Name: ";
	std::cin >> this->first_name;
	std::cout << "Last Name: ";
	std::cin >> this->last_name;
	std::cout << "Nickname: ";
	std::cin >> this->nickname;
	std::cout << "Phone Number: ";
	std::cin >> this->phone_number;
	std::cout << "Darkest Secret: ";
	std::cin >> this->darkest_secret;
}

Contact::~Contact(void)
{
	return ;
}

Phonebook::Phonebook(void)
{
	return ;
}

Phonebook::~Phonebook(void)
{
	return ;
}

void Phonebook::Search(void)
{
	int i = 0;
	std::string str;
	
	if (this->contacts[i].first_name[0] == '\0')
	{
		std::cout << "		No contacts available" << std::endl;
		return ;
	}
	std::cout << "		Index	|	First Name	|	Last Name	|	Nickname" << std::endl;
	while (this->contacts[i].first_name.length() != 0 && i < 8)
	{
		std::cout << "		       " << i << "|	      ";
		ft_printer(this->contacts[i].first_name);
		std::cout << "|	      ";
		ft_printer(this->contacts[i].last_name);
		std::cout << "|	      ";
		ft_printer(this->contacts[i].nickname);
		std::cout << std::endl;
		i++;
	}
	std::cout << "Please enter the index of the contact you want to see: ";
	std::cin >> str;
	ft_searcher(str, this);
}
