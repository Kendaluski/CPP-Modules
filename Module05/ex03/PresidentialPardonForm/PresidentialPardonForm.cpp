/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 12:39:18 by jjaen-mo          #+#    #+#             */
/*   Updated: 2024/10/25 13:56:31 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
 
PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	std::cout << "\t" << BLACK << "PresidentialPardonForm constructor called" << RESET << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "\t" << BLACK << "PresidentialPardonForm destructor called" << RESET << std::endl;
}

const std::string &PresidentialPardonForm::getTarget() const
{
	return (this->_target);
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if(executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
	else if (this->getSigned() == false)
		throw AForm::FormNotSignedException();
	else
		std::cout << "\t" << BLACK << this->getTarget() << " has been pardoned by Zafod Beeblebrox" << RESET << std::endl;
}

std::ostream &operator<<(std::ostream &out, const PresidentialPardonForm &presidentialpardonform)
{
	out << "PresidentialPardonForm with target: " << presidentialpardonform.getTarget() <<
	", grade needed to sign: " << presidentialpardonform.getGradeToSign() << 
	", and grade needed to execute: " << presidentialpardonform.getGradeToExecute() << std::endl;
	return (out);
}