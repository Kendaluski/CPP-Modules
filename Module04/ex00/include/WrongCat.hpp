/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 04:49:27 by jjaen-mo          #+#    #+#             */
/*   Updated: 2024/04/15 05:17:17 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
 # define WRONGCAT_HPP

# include <iostream>
# include "../include/WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
    public:
        WrongCat();
        WrongCat(const WrongCat &wrongcat);
        virtual ~WrongCat();
        void makeSound() const;
        WrongCat & operator = (const WrongCat &wrongcat);
};
 
std::ostream & operator << (std::ostream &out, const WrongCat &wrongcat);
 
#endif