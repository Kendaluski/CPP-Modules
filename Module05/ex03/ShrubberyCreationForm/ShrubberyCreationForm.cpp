/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 04:46:14 by jjaen-mo          #+#    #+#             */
/*   Updated: 2024/10/25 13:57:13 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	std::cout << "\t" << BLACK << "ShrubberyCreationForm constructor called" << RESET << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "\t" << BLACK << "ShrubberyCreationForm destructor called" << RESET << std::endl;
}

const std::string &ShrubberyCreationForm::getTarget() const
{
	return (_target);
}

std::ostream &operator<<(std::ostream &out, const ShrubberyCreationForm &shrubberycreationform)
{
	out << "ShrubberyCreationForm with target: " << shrubberycreationform.getTarget() <<
	", grade needed to sign: " << shrubberycreationform.getGradeToSign() << 
	", and grade needed to execute: " << shrubberycreationform.getGradeToExecute() << std::endl;
	return (out);
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if(executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
	else if (this->getSigned() == false)
		throw AForm::FormNotSignedException();
	else
	{
		std::string filename = this->getTarget() + "_shrubbery";
		std::ofstream of (filename.c_str(), std::ofstream::out);
		if(!of.is_open())
			throw std::runtime_error("Error: could not open file");
		
		of << "       _-_\n";
        of << "    /~~   ~~\\\n";
        of << " /~~         ~~\\\n";
        of << "{               }\n";
        of << " \\  _-     -_  /\n";
        of << "   ~  \\ //  ~\n";
        of << "_- -   | | _- _\n";
        of << "  _ -  | |   -_\n";
        of << "      // \\\n";
		
		of.close();
	}
}
