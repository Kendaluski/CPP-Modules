/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 04:47:23 by jjaen-mo          #+#    #+#             */
/*   Updated: 2024/04/16 05:12:31 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
 # define CHARACTER_HPP

# include <iostream>
# include "../include/ICharacter.hpp"

class Character : public ICharacter
{
    private:
        std::string _name;
        AMateria *_inv[4];
    public:
        Character();
        Character(std::string name);
        Character(const Character &character);
        ~Character();
        virtual void equip(AMateria *m);
        virtual void unequip(int idx);
        virtual void use(int idx, ICharacter &target);
        std::string const & getName() const;
        AMateria *getMat(int idx) const;
        Character & operator = (const Character &character);
};

#endif