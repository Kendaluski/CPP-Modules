/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 08:50:10 by jjaen-mo          #+#    #+#             */
/*   Updated: 2024/10/01 09:27:32 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("Default"), _signed(false), _gradeToSign(150), _gradeToExecute(150)
{
	std::cout << "\t" << BLUE << "Default constructor called on " << this->getName() << RESET << std::endl;
}

AForm::AForm(std::string name) : _name(name), _signed(false), _gradeToSign(150), _gradeToExecute(150)
{
	std::cout << "\t" << BLUE << "Name constructor called on " << this->getName() << RESET << std::endl;
}

AForm::AForm(int gradeToSign, int gradeToExecute) : _name("Default"), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	std::cout << "\t" << BLUE << "Grade constructor called on " << this->getName() << RESET << std::endl;
	if(gradeToSign < 1 || gradeToExecute < 1)
	{
		throw AForm::GradeTooHighException();
	}
	else if(gradeToSign > 150 || gradeToExecute > 150)
	{
		throw AForm::GradeTooLowException();
	}
}

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	std::cout << "\t" << BLUE << "Name and grade constructor called on " << this->getName() << RESET << std::endl;
	if(gradeToSign < 1 || gradeToExecute < 1)
	{
		throw AForm::GradeTooHighException();
	}
	else if(gradeToSign > 150 || gradeToExecute > 150)
	{
		throw AForm::GradeTooLowException();
	}
}

AForm::~AForm()
{
	std::cout << "\t" << MAGENTA << "Destructor called on " << this->getName() << RESET << std::endl;
}

std::string AForm::getName() const
{
	return (_name);
}

bool AForm::getSigned() const
{
	return (_signed);
}

int AForm::getGradeToSign() const
{
	return (_gradeToSign);
}

int AForm::getGradeToExecute() const
{
	return (_gradeToExecute);
}

void AForm::beSigned(Bureaucrat &bureaucrat)
{
	if(bureaucrat.getGrade() <= this->getGradeToSign())
	{
		_signed = true;
		std::cout << "\t" << YELLOW << bureaucrat.getName() << " signed " << this->getName() << RESET << std::endl;
	}
	else
	{
		throw AForm::GradeTooLowException();
	}
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return ("Form is not signed");
}

std::ostream &operator<<(std::ostream &out, const AForm &Aform)
{
	out << Aform.getName() << " is " << (Aform.getSigned() ? "signed" : "not signed") << 
	" and requires a grade " << Aform.getGradeToSign() << 
	" to sign and a grade " << Aform.getGradeToExecute() << 
	" to execute." << std::endl;
	return (out);
}