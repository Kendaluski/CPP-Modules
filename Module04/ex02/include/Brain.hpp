/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 05:23:46 by jjaen-mo          #+#    #+#             */
/*   Updated: 2024/04/15 05:30:05 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
 # define BRAIN_HPP

# include <iostream>

class Brain
{
    private:
        std::string ideas[100];
    public:
        Brain();
        Brain(const Brain &brain);
        ~Brain();

        std::string getIdea() const;

        Brain & operator = (const Brain &brain);
};
 
std::ostream & operator << (std::ostream &out, const Brain &brain);
 
#endif