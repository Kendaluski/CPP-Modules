/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 05:13:20 by jjaen-mo          #+#    #+#             */
/*   Updated: 2024/04/16 06:31:16 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/MateriaSource.hpp"
 
MateriaSource::MateriaSource()
{
    std::cout << "MateriaSource constructor called" << std::endl;
    for(int i = 0; i < 4; i++)
        this->_materias[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &materiasource)
{
    std::cout << "Copy constructor called" << std::endl;
    for(int i = 0; i < 4; i++)
    {
        if(materiasource._materias[i] != NULL)
            this->_materias[i] = materiasource._materias[i];
        else
            delete this->_materias[i];
    }
}

MateriaSource::~MateriaSource()
{
    std::cout << "MateriaSource destructor called" << std::endl;
    for(int i = 0; i < 4; i++)
        if(this->_materias[i] != NULL)
            delete this->_materias[i];
}

void MateriaSource::learnMateria(AMateria *m)
{
    int i = 0;

    for(int i = 0; i < 4; i++)
    {
        if(this->_materias[i] == NULL)
        {
            this->_materias[i] = m;
            break;
        }
    }
    if(i == 4)
        std::cout << "Can't add more materias to the index" << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for(int i = 0; i < 4; i++)
    {
        if(this->_materias[i] != NULL && this->_materias[i]->getType() == type)
            return (this->_materias[i]);
    }
    return (NULL);
}

MateriaSource & MateriaSource::operator = (const MateriaSource &materiasource)
{
    std::cout << "Copy operator called" << std::endl;
    for(int i = 0; i < 4; i++)
    {
        if(materiasource._materias[i] != NULL)
            this->_materias[i] = materiasource._materias[i];
        else
            delete this->_materias[i];
    }
    return (*this);
}
