/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 12:39:17 by jjaen-mo          #+#    #+#             */
/*   Updated: 2024/10/25 12:40:29 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
 # define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include "../AForm/AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		std::string _target;
	public:
		PresidentialPardonForm(std::string target);
		const std::string &getTarget() const;
		~PresidentialPardonForm();

		void execute(Bureaucrat const &executor) const;
};
 
std::ostream & operator << (std::ostream &out, const PresidentialPardonForm &presidentialpardonform);
 
#endif