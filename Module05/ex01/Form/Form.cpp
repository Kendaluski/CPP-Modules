/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 08:50:10 by jjaen-mo          #+#    #+#             */
/*   Updated: 2024/10/01 09:27:32 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("Default"), _signed(false), _gradeToSign(150), _gradeToExecute(150)
{
	std::cout << "Default constructor called on " << this->getName() << std::endl;
}

Form::Form(std::string name) : _name(name), _signed(false), _gradeToSign(150), _gradeToExecute(150)
{
	std::cout << "Name constructor called on " << this->getName() << std::endl;
}

Form::Form(int gradeToSign, int gradeToExecute) : _name("Default"), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	std::cout << "Grade constructor called on " << this->getName() << std::endl;
	if(gradeToSign < 1 || gradeToExecute < 1)
	{
		throw Form::GradeTooHighException();
	}
	else if(gradeToSign > 150 || gradeToExecute > 150)
	{
		throw Form::GradeTooLowException();
	}
}

Form::Form(std::string name, int gradeToSign, int gradeToExecute) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	std::cout << "Name and grade constructor called on " << this->getName() << std::endl;
	if(gradeToSign < 1 || gradeToExecute < 1)
	{
		throw Form::GradeTooHighException();
	}
	else if(gradeToSign > 150 || gradeToExecute > 150)
	{
		throw Form::GradeTooLowException();
	}
}

Form::Form(const Form &form) : _name(form.getName()), _signed(form.getSigned()), _gradeToSign(form.getGradeToSign()), _gradeToExecute(form.getGradeToExecute())
{
	std::cout << "Copy constructor called on " << this->getName() << std::endl;
	*this = form;
}

Form::~Form()
{
	std::cout << "Destructor called on " << this->getName() << std::endl;
}

Form & Form::operator = (const Form &form)
{
	std::cout << "Copy operator called on " << this->getName() << std::endl;
	if (this != &form)
	{
		_signed = form.getSigned();
	}
	return (*this);
}

std::string Form::getName() const
{
	return (_name);
}

bool Form::getSigned() const
{
	return (_signed);
}

int Form::getGradeToSign() const
{
	return (_gradeToSign);
}

int Form::getGradeToExecute() const
{
	return (_gradeToExecute);
}

void Form::beSigned(Bureaucrat &bureaucrat)
{
	if(bureaucrat.getGrade() <= this->getGradeToSign())
	{
		_signed = true;
		std::cout << bureaucrat.getName() << " signed " << this->getName() << std::endl;
	}
	else
	{
		throw Form::GradeTooLowException();
	}
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

std::ostream &operator<<(std::ostream &out, const Form &form)
{
	out << form.getName() << " is " << (form.getSigned() ? "signed" : "not signed") << 
	" and requires a grade " << form.getGradeToSign() << 
	" to sign and a grade " << form.getGradeToExecute() << 
	" to execute." << std::endl;
	return (out);
}