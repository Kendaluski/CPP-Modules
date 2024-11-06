/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 13:34:03 by jjaen-mo          #+#    #+#             */
/*   Updated: 2024/11/06 16:31:13 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./BitcoinExchange/BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if(argc != 2)
	{
		std::cerr << RED << "[ERROR] Usage: ./btc input" << RESET << std::endl;
		return (1);
	}
	BitcoinExchange btc("data.csv");

	btc.convertInput(argv[1]);
	return (0);
}