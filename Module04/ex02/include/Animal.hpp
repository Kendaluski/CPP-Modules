/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 08:31:01 by jjaen-mo          #+#    #+#             */
/*   Updated: 2024/04/15 05:53:53 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
 # define ANIMAL_HPP

# include <iostream>
# include <string>

class Animal
{
    protected:
        std::string type;
        Animal();
        Animal(const Animal &animal);
    public:
        virtual ~Animal();
        std::string getType() const;
        void setType(std::string type);
        virtual void makeSound() const;
        Animal & operator = (const Animal &animal);
};
 
std::ostream & operator << (std::ostream &out, const Animal &animal);
 
#endif