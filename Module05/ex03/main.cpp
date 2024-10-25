/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 08:02:54 by jjaen-mo          #+#    #+#             */
/*   Updated: 2024/10/25 16:02:24 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm/AForm.hpp"
#include "ShrubberyCreationForm/ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm/RobotomyRequestForm.hpp"
#include "PresidentialPardonForm/PresidentialPardonForm.hpp"
#include "Bureaucrat/Bureaucrat.hpp"
#include "Intern/Intern.hpp"

int main(void)
{
    Bureaucrat b1("Juan", 1);
    Intern i1;
    AForm *f1;
    AForm *f2;
    AForm *f3;
    AForm *f4;

    std::cout << "<------------------------------------------------------------------------------------------------------------>" << std::endl;

    f1 = i1.makeForm("shrubbery creation", "home");
    if(f1 != NULL)
    {
        std::cout << CYAN << "\t" << *f1 << RESET;
        b1.signForm(*f1);
        b1.executeForm(*f1);
        delete f1;
    }

    std::cout << "<------------------------------------------------------------------------------------------------------------>" << std::endl;

    f2 = i1.makeForm("RoBoToMy ReQuEsT", "home");
    if(f2 != NULL)
    {
        std::cout << CYAN << "\t" << *f2 << RESET;
        b1.signForm(*f2);
        b1.executeForm(*f2);
        b1.executeForm(*f2);
        delete f2;
    }
    
    std::cout << "<------------------------------------------------------------------------------------------------------------>" << std::endl;

    f3 = i1.makeForm("PresidentialPardonForm", "home");
    if(f3 != NULL)
    {
        std::cout << CYAN << "\t" << *f3 << RESET;
        b1.signForm(*f3);
        b1.executeForm(*f3);
        delete f3;
    }
    
    std::cout << "<------------------------------------------------------------------------------------------------------------>" << std::endl;

    f4 = i1.makeForm("Error", "home");
    if(f4 != NULL)
    {
        std::cout << CYAN << "\t" << *f4 << RESET;
        b1.signForm(*f4);
        b1.executeForm(*f4);
        delete f4;
    }
    
    std::cout << "<------------------------------------------------------------------------------------------------------------>" << std::endl;
    return (0);
}