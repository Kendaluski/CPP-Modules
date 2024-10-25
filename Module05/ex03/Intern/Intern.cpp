/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 14:04:20 by jjaen-mo          #+#    #+#             */
/*   Updated: 2024/10/25 16:04:22 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
 
Intern::Intern()
{
	std::cout << "\tIntern default constructor called" << std::endl;
}

Intern::~Intern()
{
	std::cout << RED << "\tIntern destructor called" << RESET << std::endl;
}

char toLowerChar(char c) {
    return std::tolower(static_cast<unsigned char>(c));
}

std::string to_lower(std::string str)
{
	std::transform(str.begin(), str.end(), str.begin(), toLowerChar);
	return (str);
}

int check_form(std::string name)
{
	int i = 0;
	std::string forms[3] = {"shrubbery", "robotomy", "presidential"};
	std::string lower = to_lower(name);
	for(i = 0; i < 3; i++)
	{
		if(lower.find(forms[i]) != std::string::npos)
			return (i);
	}
	return (-1);
}

AForm* Intern::makeForm(std::string formName, std::string target)
{
	int i = 0;
	
	std::cout << GREEN << "\tIntern tries to make form " << formName << RESET << std::endl;
	i = check_form(formName);
	switch(i)
	{
		case 0:
			return (new ShrubberyCreationForm(target));
		case 1:
			return (new RobotomyRequestForm(target));
		case 2:
			return (new PresidentialPardonForm(target));
		default:
			std::cout << RED << "\tError: Form name " << formName << " not found" << RESET << std::endl;
			return (NULL);
	}
	
}

std::ostream &operator<<(std::ostream &out, const Intern &intern)
{
	out << "Intern " << &intern << std::endl;
	return (out);
}