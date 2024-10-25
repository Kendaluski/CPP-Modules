/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 14:04:22 by jjaen-mo          #+#    #+#             */
/*   Updated: 2024/10/25 15:36:08 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
 # define INTERN_HPP

# include <iostream>
# include "../AForm/AForm.hpp"
# include "../ShrubberyCreationForm/ShrubberyCreationForm.hpp"
# include "../RobotomyRequestForm/RobotomyRequestForm.hpp"
# include "../PresidentialPardonForm/PresidentialPardonForm.hpp"
# include <algorithm>
# include <cctype>

class Intern
{
	private:
	public:
		Intern();
		~Intern();
		
		AForm* makeForm(std::string formName, std::string target);
};
 
std::ostream & operator << (std::ostream &out, const Intern &intern);
 
#endif