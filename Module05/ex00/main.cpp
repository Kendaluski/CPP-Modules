/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 08:02:54 by jjaen-mo          #+#    #+#             */
/*   Updated: 2024/10/01 08:45:48 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat/Bureaucrat.hpp"

int main(void)
{
    Bureaucrat b1("Juan", 1);
    Bureaucrat b2("Yuan");
    Bureaucrat b3(150);
    Bureaucrat b4;

    std::cout << "<--------------------------------------------------->" << std::endl;

    std::cout << b1;
    std::cout << b2;
    std::cout << b3;
    std::cout << b4;
    
    std::cout << "<--------------------------------------------------->" << std::endl;

    try
    {
        Bureaucrat b5("Juanin", 0);
    }
    catch(Bureaucrat::GradeTooHighException &e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        Bureaucrat b6("Juanito", 200);
    }
    catch(Bureaucrat::GradeTooLowException &e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        b1.incrementGrade();
    }
    catch(Bureaucrat::GradeTooHighException &e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        b3.decrementGrade();
    }
    catch(Bureaucrat::GradeTooLowException &e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "<--------------------------------------------------->" << std::endl;
}