/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 12:29:09 by jjaen-mo          #+#    #+#             */
/*   Updated: 2024/10/25 13:57:07 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
 
RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout << "\t" << BLACK << "RobotomyRequestForm constructor called" << RESET << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "\t" << BLACK << "RobotomyRequestForm destructor called" << RESET << std::endl;
}

const std::string &RobotomyRequestForm::getTarget() const
{
	return (this->_target);
}

std::ostream &operator<<(std::ostream &out, const RobotomyRequestForm &robotomyrequestform)
{
	out << "RobotomyRequestForm with target: " << robotomyrequestform.getTarget() <<
	", grade needed to sign: " << robotomyrequestform.getGradeToSign() << 
	", and grade needed to execute: " << robotomyrequestform.getGradeToExecute() << std::endl;
	return (out);
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if(executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
	else if (this->getSigned() == false)
		throw AForm::FormNotSignedException();
	else
	{
		std::cout << "\t" << BLACK << "Drilling noises" << std::endl;
		if (rand() % 2 == 0)
			std::cout << "\t" << this->getTarget() << " has been robotomized successfully" << RESET << std::endl;
		else
			std::cout << "\t" << this->getTarget() << " robotomization failed" << RESET << std::endl;
	}
}
