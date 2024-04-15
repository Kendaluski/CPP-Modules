/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 05:23:48 by jjaen-mo          #+#    #+#             */
/*   Updated: 2024/04/15 05:42:40 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Brain.hpp"
 
Brain::Brain()
{
    std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(const Brain &brain)
{
    std::cout << "Copy constructor called" << std::endl;
    for (int i = 0; i < 100; i++)
        this->ideas[i] = brain.ideas[i];
}

Brain::~Brain()
{
    std::cout << "Brain destructor called" << std::endl;
}

Brain & Brain::operator = (const Brain &brain)
{
    std::cout << "Copy operator called" << std::endl;
    for (int i = 0; i < 100; i++)
        this->ideas[i] = brain.ideas[i];
    return (*this);
}

std::string Brain::getIdea() const
{
    return (this->ideas[0]);
} 

std::ostream &operator<<(std::ostream &out, const Brain &brain)
{
    out << brain.getIdea() << std::endl;
    return (out);
}