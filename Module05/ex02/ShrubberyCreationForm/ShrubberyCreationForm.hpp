/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 04:46:12 by jjaen-mo          #+#    #+#             */
/*   Updated: 2024/10/08 05:17:04 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
 # define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include "../AForm/AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
		std::string _target;
	public:
		ShrubberyCreationForm(std::string target);
		const std::string &getTarget() const;
		~ShrubberyCreationForm();

		void execute(Bureaucrat const &executor) const;
};
 
std::ostream & operator << (std::ostream &out, const ShrubberyCreationForm &shrubberycreationform);
 
#endif