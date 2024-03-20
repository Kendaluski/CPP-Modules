/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 03:17:19 by jjaen-mo          #+#    #+#             */
/*   Updated: 2024/03/20 18:06:34 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <map>

class Harl 
{
	private:
		void debug ( void );
		void info ( void );
		void warning ( void );
		void error ( void );
	public:
		void complain( std::string level );
};
 