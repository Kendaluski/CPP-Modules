/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 07:53:02 by jjaen-mo          #+#    #+#             */
/*   Updated: 2024/10/31 08:47:05 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
 # define SERIALIZER_HPP

# include <iostream>
# include "Data.hpp"

# define RED "\033[31m"
# define GREEN "\033[32m"
# define ORANGE "\033[38;5;214m"
# define MAGENTA "\033[35m"
# define RESET "\033[0m"

class Serializer
{
	private:
		Serializer();
		Serializer(const Serializer &Serializer);
	public:
		~Serializer();
		Serializer & operator = (const Serializer &Serializer);
		static unsigned long serialize(Data *ptr);
		static Data *deserialize(unsigned long raw);
};

std::ostream & operator << (std::ostream &out, const Serializer &Serializer);

 
#endif