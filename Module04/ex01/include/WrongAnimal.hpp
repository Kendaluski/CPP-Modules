/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 04:50:21 by jjaen-mo          #+#    #+#             */
/*   Updated: 2024/04/15 05:20:29 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
 # define WRONGANIMAL_HPP

# include <iostream>

class WrongAnimal
{
    protected:
        std::string type;
    public:
        WrongAnimal();
        WrongAnimal(const WrongAnimal &wronganimal);
        virtual ~WrongAnimal();
        
        std::string getType() const;
        void setType(std::string type);
        virtual void makeSound() const;
        WrongAnimal & operator = (const WrongAnimal &wronganimal);
};
 
std::ostream & operator << (std::ostream &out, const WrongAnimal &wronganimal);
 
#endif