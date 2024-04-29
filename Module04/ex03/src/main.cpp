/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 05:59:57 by jjaen-mo          #+#    #+#             */
/*   Updated: 2024/04/29 18:28:46 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Character.hpp"
#include "../include/MateriaSource.hpp"
#include "../include/IMateriaSource.hpp"
#include "../include/Ice.hpp"
#include "../include/Cure.hpp"

void ft_leaks(void)
{
    system("leaks -q interfaces");
}

int main()
{
    atexit(ft_leaks);
    IMateriaSource *src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    ICharacter* me = new Character("me");

    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    ICharacter* bob = new Character("bob");
    tmp = src->createMateria("cure");
    me->equip(tmp);
    me->use(0, *bob);
    me->use(1, *bob);
    me->use(2, *bob);
    me->use(3, *bob);
    me->use(4, *bob);
    me->unequip(0);
    me->unequip(15);
    me->use(0, *bob);
    delete bob;
    delete me;
    delete src;
    return 0;
}