/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 09:08:41 by jjaen-mo          #+#    #+#             */
/*   Updated: 2024/04/10 06:50:23 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Point.hpp"

int main()
{
    Point a(Fixed(0), Fixed(0));
    Point b(Fixed(0), Fixed(1));
    Point c(Fixed(1), Fixed(0));
    Point point(Fixed((float)0.5), Fixed((float)0.5));
    Point point2(Fixed(5), Fixed(5));

    std::cout << "Point A: " << a << std::endl;
    std::cout << "Point B: " << b << std::endl;
    std::cout << "Point C: " << c << std::endl;
    std::cout << "Point P: " << point << std::endl;
    if(bsp(a, b, c, point))
        std::cout << "The point P is inside the triangle ABC" << std::endl;
    else
        std::cout << "The point P is outside the triangle ABC" << std::endl;
    if(bsp(a, b, c, point2))
        std::cout << "The point P is inside the triangle ABC" << std::endl;
    else
        std::cout << "The point P is outside the triangle ABC" << std::endl;
    return 0;
}