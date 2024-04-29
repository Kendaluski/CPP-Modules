/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 08:46:40 by jjaen-mo          #+#    #+#             */
/*   Updated: 2024/04/29 18:13:14 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Animal.hpp"
#include "include/Dog.hpp"
#include "include/Cat.hpp"
#include "include/Brain.hpp"

void ft_leaks()
{
    system("leaks -q ideas");
}

int main()
{
    Animal *animals[4];
    
    atexit(ft_leaks);
    for(int i = 0; i < 4; i++)
    {
        if(i % 2 == 0)
            animals[i] = new Cat();
        else
            animals[i] = new Dog();
    }
    std::cout << std::endl; 
    std::cout << "All animals created" << std::endl;
    std::cout << std::endl;
    for(int i = 0; i < 4; i++)
        delete animals[i];
    return 0;
}