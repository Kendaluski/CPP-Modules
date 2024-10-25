/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 08:04:15 by jjaen-mo          #+#    #+#             */
/*   Updated: 2024/10/25 14:02:31 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150)
{
	std::cout << "\t" << GREEN << "Default constructor called on " << this->getName() << 
    " with grade " << this->getGrade() << RESET << std::endl;
}

Bureaucrat::Bureaucrat(std::string name) : _name(name), _grade(150)
{
    std::cout << "\t" << GREEN << "Name constructor called on " << this->getName() << RESET << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
    std::cout << "\t" << GREEN << "Name and grade constructor called on " << this->getName() << RESET << std::endl;
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    _grade = grade;
}

Bureaucrat::Bureaucrat(int grade) : _name("Default")
{
    std::cout << "\t" << GREEN << "Grade constructor called on " << this->getName() << RESET << std::endl;
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    _grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &bureaucrat) : _name(bureaucrat.getName()), _grade(bureaucrat.getGrade())
{
	std::cout << "Copy constructor called on " << this->getName() << std::endl;
    *this = bureaucrat;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "\t" << RED << "Destructor called on " << this->getName() << RESET << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &bureaucrat)
{
	std::cout << "Copy operator called on " << this->getName() << std::endl;
    if (this != &bureaucrat)
    {
        _grade = bureaucrat.getGrade();
    }
    return (*this);
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat)
{
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << std::endl;
	return (out);
}

std::string Bureaucrat::getName() const
{
	return (_name);
}

int Bureaucrat::getGrade() const
{
	return (_grade);
}

void Bureaucrat::incrementGrade()
{
	if (_grade == 1)
		throw Bureaucrat::GradeTooHighException();
	_grade--;
}

void Bureaucrat::decrementGrade()
{
	if (_grade == 150)
		throw Bureaucrat::GradeTooLowException();
	_grade++;
}

void Bureaucrat::signForm(AForm &form)
{
    if (_grade <= form.getGradeToSign())
    {
        form.beSigned(*this);
    }
    else
    {
        std::cout << "\t" << RED << this->getName() << " couldn't sign " << form.getName() << " because his grade is too low" << RESET << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const &form) const
{
    if(_grade <= form.getGradeToExecute())
    {
        std::cout << "\t" << ORANGE << this->getName() << " executes " << form.getName() << RESET << std::endl;
        form.execute(*this);
    }
    else
    {
        std::cout << "\t" << RED << this->getName() << " couldn't execute " << form.getName() << " because its grade is too low" << RESET << std::endl;
    }
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}
