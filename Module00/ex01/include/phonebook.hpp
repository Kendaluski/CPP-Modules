/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 19:42:26 by jjaen-mo          #+#    #+#             */
/*   Updated: 2024/03/12 19:53:50 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include <iostream>
# include <string>

class Contact
{
	public:
		Contact(void);
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string phone_number;
		std::string darkest_secret;
		void Create(void);
		~Contact(void);
};

class Phonebook
{
  public:
	Phonebook(void);
	Contact contacts[8];
	void Search(void);
	~Phonebook(void);
};

int ft_strncmp(const char *s1, const char *s2, int j);
void ft_searcher(std::string str, Phonebook *phonebook);
void ft_printer(std::string str);

#endif