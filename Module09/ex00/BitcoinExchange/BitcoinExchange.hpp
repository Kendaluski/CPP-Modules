/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 13:34:17 by jjaen-mo          #+#    #+#             */
/*   Updated: 2024/11/06 16:33:51 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
 # define BITCOINEXCHANGE_HPP

# include <iostream>
# include <map>
# include <string>
# include <exception>
# include <fstream>
# include <cstdlib>

# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define ORANGE "\033[38;5;214m"
# define CYAN "\033[92m"
# define MAGENTA "\033[35m"
# define BLACK "\033[30m"
# define BLUE "\033[34m"
# define RESET "\033[0m"

class BitcoinExchange
{
	private:
		std::map<std::string, float> _data;
		std::map<std::string, float>::iterator _it;
		std::map<std::string, float>::iterator _inputit;
	public:
		BitcoinExchange(std::string filename);
		BitcoinExchange(const BitcoinExchange &bitcoinexchange);
		~BitcoinExchange();
		BitcoinExchange & operator = (const BitcoinExchange &bitcoinexchange);

		void printData();
		void convertInput(std::string input);
};
 
std::ostream & operator << (std::ostream &out, const BitcoinExchange &bitcoinexchange);
 
#endif