/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 08:46:40 by jjaen-mo          #+#    #+#             */
/*   Updated: 2024/04/29 18:01:08 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Animal.hpp"
#include "include/Dog.hpp"
#include "include/Cat.hpp"
#include "include/WrongAnimal.hpp"
#include "include/WrongCat.hpp"

// void ft_leaks()
// {
//     system("leaks -q animal");
// }

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    const WrongAnimal* wrongmeta = new WrongAnimal();
    const WrongAnimal* wrongj = new WrongCat();
    
    // atexit(ft_leaks);
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    std::cout << wrongj->getType() << " " << std::endl;
    i->makeSound();
    j->makeSound();
    meta->makeSound();
    wrongmeta->makeSound();
    wrongj->makeSound();
    delete meta;
    delete j;
    delete i;
    delete wrongmeta;
    delete wrongj;
    return 0;
}