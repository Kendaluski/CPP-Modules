/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 07:53:13 by jjaen-mo          #+#    #+#             */
/*   Updated: 2024/10/31 08:25:48 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer/Serializer.hpp"

int main()
{
	Data data;
	data.s = "Chema";
	data.n = 42;
	
	std::cout << MAGENTA << "Data before serialization: " << &data << std::endl;
	std::cout << "Data s: " << data.s << " n: " << data.n << std::endl;
	std::cout << "Data after serialization: " << Serializer::deserialize(Serializer::serialize(&data)) << std::endl;
	std::cout << "Data s: " << data.s << " n: " << data.n << RESET << std::endl;
}