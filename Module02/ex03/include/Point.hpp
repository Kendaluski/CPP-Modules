/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 09:12:33 by jjaen-mo          #+#    #+#             */
/*   Updated: 2024/04/09 09:19:13 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
 # define POINT_HPP

# include <iostream>
# include "Fixed.hpp"

class Point
{
    private:
        Fixed const _x;
        Fixed const _y;
    public:
        Point();
        Point(const Point &point);
        Point(Fixed const x, Fixed const y);
        ~Point();

        Fixed getX() const;
        Fixed getY() const;
        
        Point & operator = (const Point &point);
};
 
std::ostream & operator << (std::ostream &out, const Point &point);
 
#endif