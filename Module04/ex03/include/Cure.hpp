/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 06:10:20 by jjaen-mo          #+#    #+#             */
/*   Updated: 2024/04/15 06:31:53 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
 # define CURE_HPP

# include <iostream>
# include "AMateria.hpp"

class Cure
{
    private:
    public:
        Cure();
        Cure(const Cure &cure);
        ~Cure();
        Cure *clone() const;
        void use(ICharacter& target);
        Cure & operator = (const Cure &cure);
};
 
std::ostream & operator << (std::ostream &out, const Cure &cure);
 
#endif