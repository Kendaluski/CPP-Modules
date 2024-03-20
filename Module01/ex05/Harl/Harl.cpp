/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 03:17:23 by jjaen-mo          #+#    #+#             */
/*   Updated: 2024/03/20 03:42:01 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug ( void )
{
	std::cout << "Vamo a proba si eto funsiona " << std::endl;
}

void Harl::info ( void )
{
	std::cout << "Eto eta funsionando " << std::endl;
}

void Harl::warning ( void )
{
	std::cout << "Cuidao que eto no va bien " << std::endl;
}

void Harl::error ( void )
{
	std::cout << "Eto no va " << std::endl;
}

void Harl::complain( std::string level )
{
	std::map<std::string, void (Harl::*)()> map;
	
	map["DEBUG"] = &Harl::debug;
	map["INFO"] =  &Harl::info;
	map["WARNING"] = &Harl::warning;
	map["ERROR"] = &Harl::error;
	
	if(map.find(level) != map.end())
		(this->*map[level])();
	else
		std::cout << "Nivel de log no válido" << std::endl;
}
