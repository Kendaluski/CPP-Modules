/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 08:39:36 by jjaen-mo          #+#    #+#             */
/*   Updated: 2024/04/15 05:16:48 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
 # define CAT_HPP

# include <iostream>
# include "Animal.hpp"

class Cat : public Animal
{
    private:
    public:
        Cat();
        Cat(const Cat &cat);
        virtual ~Cat();
        void makeSound() const;
        Cat & operator = (const Cat &cat);
};
 
std::ostream & operator << (std::ostream &out, const Cat &cat);
 
#endif