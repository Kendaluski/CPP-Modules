/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 08:02:54 by jjaen-mo          #+#    #+#             */
/*   Updated: 2024/10/25 14:01:00 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm/AForm.hpp"
#include "ShrubberyCreationForm/ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm/RobotomyRequestForm.hpp"
#include "PresidentialPardonForm/PresidentialPardonForm.hpp"
#include "Bureaucrat/Bureaucrat.hpp"

int main(void)
{
    Bureaucrat b1("Juan", 1);
    Bureaucrat b2("chema", 150);
    ShrubberyCreationForm f1("home");
    RobotomyRequestForm f2("chema");
    PresidentialPardonForm f3("chema");

    std::cout << "<------------------------------------------------------------------------------------------------------------>" << std::endl;

    std::cout << CYAN << "\t" << b1 << RESET;
    std::cout << CYAN << "\t" << f1 << RESET;
    std::cout << CYAN << "\t" << f2 << RESET;
    std::cout << CYAN << "\t" << f3 << RESET;
    
    std::cout << "<------------------------------------------------------------------------------------------------------------>" << std::endl;

    b1.signForm(f1);
    b2.signForm(f2);
    b1.signForm(f2);
    b1.signForm(f3);
    
    std::cout << "<------------------------------------------------------------------------------------------------------------>" << std::endl;

    b1.executeForm(f1);
    b1.executeForm(f2);
    b1.executeForm(f2);
    b2.executeForm(f3);
    b1.executeForm(f3);
    
    std::cout << "<------------------------------------------------------------------------------------------------------------>" << std::endl;
}