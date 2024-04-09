/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 11:22:08 by jjaen-mo          #+#    #+#             */
/*   Updated: 2024/04/09 08:28:15 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
 
# include <iostream>
 
class Fixed
{
   private:
       int _value;
       static const int _fractionalBits = 8;
   public:
       Fixed();
       Fixed(const Fixed &fixed);
       ~Fixed();

       int getRawBits(void) const;
       void setRawBits(int const raw);
       
       Fixed & operator = (const Fixed &fixed);
};
 
#endif