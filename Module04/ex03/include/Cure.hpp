/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 06:10:20 by jjaen-mo          #+#    #+#             */
/*   Updated: 2024/04/16 05:40:09 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
 # define CURE_HPP

# include <iostream>
# include "AMateria.hpp"

class Cure : public AMateria
{
    private:
    public:
        Cure();
        Cure(const Cure &cure);
        ~Cure();
        Cure *clone() const;
        void use(ICharacter& target);
};
 
#endif