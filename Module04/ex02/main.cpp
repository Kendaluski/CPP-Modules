/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 08:46:40 by jjaen-mo          #+#    #+#             */
/*   Updated: 2024/04/30 12:39:32 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Animal.hpp"
#include "include/Dog.hpp"
#include "include/Cat.hpp"
#include "include/Brain.hpp"

// void ft_leaks()
// {
//     system("leaks -q abstract");
// }

int main()
{
    Cat *cat = new Cat();
    Dog *dog = new Dog();
    // Animal *animal = new Animal();
    
    // atexit(ft_leaks);
    cat->makeSound();
    dog->makeSound();
    delete cat;
    delete dog;
    return 0;
}