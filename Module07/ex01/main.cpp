/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 09:42:59 by jjaen-mo          #+#    #+#             */
/*   Updated: 2024/10/31 09:47:16 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void print(std::string const &s)
{
	std::cout << s << std::endl;
}

int main(void)
{
	std::string array[] = {"Chema", "Gusta", "42", "Malaga"};
	::iter(array, 4, print);
}