/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 12:29:06 by jjaen-mo          #+#    #+#             */
/*   Updated: 2024/10/25 13:17:39 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
 # define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <cstdlib>
# include "../AForm/AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:
		std::string _target;
	public:
		RobotomyRequestForm(std::string target);
		const std::string &getTarget() const;
		~RobotomyRequestForm();

		void execute(Bureaucrat const &executor) const;
};
 
std::ostream & operator << (std::ostream &out, const RobotomyRequestForm &robotomyrequestform);
 
#endif