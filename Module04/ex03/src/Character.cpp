/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 04:47:21 by jjaen-mo          #+#    #+#             */
/*   Updated: 2024/04/16 06:34:36 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Character.hpp"

Character::Character()
{
    std::cout << "Character default constructor called" << std::endl;
    for(int i = 0; i < 4; i++)
        this->_inv[i] = NULL;
}

Character::Character(std::string name)
{
    _name = name;
    std::cout << "Character name constructor called" << std::endl;
    for(int i = 0; i < 4; i++)
        this->_inv[i] = NULL;
}

Character::Character(const Character &character)
{
    std::cout << "Copy constructor called" << std::endl;
    this->_name = character._name;
    for(int i = 0; i < 4; i++)
        this->_inv[i] = character._inv[i];
}

Character::~Character()
{
    std::cout << "Character destructor called" << std::endl;
    for(int i = 0; i < 4; i++)
        if(this->_inv[i] != NULL)
            this->_inv[i] = NULL;
}

void Character::equip(AMateria *m)
{
    int i = 0;
    
    for(int i = 0; i < 4; i++)
    {
        if(this->_inv[i] == NULL)
        {
            this->_inv[i] = m;
            break;
        }
    }
    if(i == 4)
        std::cout << "Inventory is full" << std::endl;
}

void Character::unequip(int idx)
{
    if(idx >= 0 && idx < 4)
        this->_inv[idx] = NULL;
    else
        std::cout << "Unable to unequip, index not in inventory" << std::endl;
}

void Character::use(int idx, ICharacter &target)
{
    if(idx >= 0 && idx < 4 && this->_inv[idx] != NULL)
        this->_inv[idx]->use(target);
    else
        std::cout << "Unable to equip, index not in inventory" << std::endl;
}

std::string const & Character::getName() const
{
    return (this->_name);
}

AMateria *Character::getMat(int idx) const
{
    if(idx >= 0 && idx < 4)
        return (this->_inv[idx]);
    return (NULL);
}

Character & Character::operator = (const Character &character)
{
    std::cout << "Copy operator called" << std::endl;
    this->_name = character._name;
    for(int i = 0; i < 4; i++)
    {
        if(character._inv[i] == NULL)
            delete this->_inv[i];
        else
            this->_inv[i] = character._inv[i];
    }
    return (*this);
}
