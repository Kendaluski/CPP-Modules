/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 04:46:14 by jjaen-mo          #+#    #+#             */
/*   Updated: 2024/10/08 05:17:11 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	std::cout << "ShrubberyCreationForm constructor called on " << this << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor called on " << this << std::endl;
}

const std::string &ShrubberyCreationForm::getTarget() const
{
	return (_target);
}

std::ostream &operator<<(std::ostream &out, const ShrubberyCreationForm &shrubberycreationform)
{
	out << "ShrubberyCreationForm [" << "" << "]";
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
		std::ofstream outfile(this->getTarget() + "_shrubbery");
		if(!outfile.is_open())
			throw std::runtime_error("Error: could not open file");
		
		outfile << "       _-_\n";
        outfile << "    /~~   ~~\\\n";
        outfile << " /~~         ~~\\\n";
        outfile << "{               }\n";
        outfile << " \\  _-     -_  /\n";
        outfile << "   ~  \\ //  ~\n";
        outfile << "_- -   | | _- _\n";
        outfile << "  _ -  | |   -_\n";
        outfile << "      // \\\n";
		
		outfile.close();
	}
}
