/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 03:17:23 by jjaen-mo          #+#    #+#             */
/*   Updated: 2024/03/20 18:30:12 by jjaen-mo         ###   ########.fr       */
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
	
	if (map.find(level) == map.end())
	{
		std::cout << "[ERROR] Enter a valid log level: ";
		std::cout << "DEBUG, INFO, WARNING, ERROR" << std::endl;
		return ;
	}
	switch(level[0])
	{
		case 'D':
			(this->*map["DEBUG"])();
			(this->*map["INFO"])();
			(this->*map["WARNING"])();
			(this->*map["ERROR"])();
			break;
		case 'I':
			(this->*map["INFO"])();
			(this->*map["WARNING"])();
			(this->*map["ERROR"])();
			break;
		case 'W':
			(this->*map["WARNING"])();
			(this->*map["ERROR"])();
			break;
		case 'E':
			(this->*map["ERROR"])();
			break;
	}
}
