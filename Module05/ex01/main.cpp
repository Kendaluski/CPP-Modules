/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 08:02:54 by jjaen-mo          #+#    #+#             */
/*   Updated: 2024/10/01 09:20:03 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form/Form.hpp"
#include "Bureaucrat/Bureaucrat.hpp"

int main(void)
{
    Bureaucrat b1("Juan", 1);
    Form f1("Form1", 1, 1);
    Form f2("Form2", 150, 150);
    Form f3("Form3");
    Form f4(150, 150);

    std::cout << "<--------------------------------------------------->" << std::endl;

    std::cout << f1;
    std::cout << f2;
    std::cout << f3;
    std::cout << f4;
    
    std::cout << "<--------------------------------------------------->" << std::endl;

    try
    {
        b1.signForm(f2);
    }
    catch(Form::GradeTooLowException &e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        b1.decrementGrade();
        b1.signForm(f1);
    }
    catch(Form::GradeTooLowException &e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "<--------------------------------------------------->" << std::endl;
}