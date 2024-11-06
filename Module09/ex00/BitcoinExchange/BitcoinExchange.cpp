/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 13:34:59 by jjaen-mo          #+#    #+#             */
/*   Updated: 2024/11/06 17:59:06 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
 
BitcoinExchange::BitcoinExchange(std::string filename)
{
	std::cout << GREEN << "BitcoinExchange default constructor called" << RESET << std::endl;
	std::ifstream file;
	
	file.open(filename.c_str());
	if (!file.is_open())
		throw std::invalid_argument( RED "[ERROR] File not found" RESET);
	
	std::cout << MAGENTA << "Data file opened, storing data..." << RESET << std::endl;
	std::string line;
	while (std::getline(file, line))
	{
		std::string key = line.substr(0, line.find(","));
		std::string value = line.substr(line.find(",") + 1);
		_data[key] = std::strtof(value.c_str(), NULL);
	}
	file.close();
	if(_data.size() == 0)
		throw std::invalid_argument( RED "[ERROR] Empty file" RESET);
	std::cout << CYAN << "Data stored" << RESET << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &bitcoinexchange)
{
	std::cout << GREEN << "BitcoinExchange copy constructor called" << RESET << std::endl;
	if(this != &bitcoinexchange)
		*this = bitcoinexchange;
}

BitcoinExchange::~BitcoinExchange()
{
	std::cout << RED << "BitcoinExchange destructor called" << RESET << std::endl;
}

BitcoinExchange & BitcoinExchange::operator = (const BitcoinExchange &bitcoinexchange)
{
	std::cout << "BitcoinExchange copy operator called" << std::endl;
	if(this != &bitcoinexchange)
	{
		this->BitcoinExchange::operator=(bitcoinexchange);
	}
	return (*this);
}
 
std::ostream &operator<<(std::ostream &out, const BitcoinExchange &bitcoinexchange)
{
	out << "BitcoinExchange [" << &bitcoinexchange << "]";
	return (out);
}

void BitcoinExchange::printData()
{
	std::cout << YELLOW;
	for(_it = _data.begin(); _it != _data.end(); _it++)
		std::cout << _it->first << " => " << _it->second << std::endl;
	std::cout << RESET;
}

void BitcoinExchange::convertInput(std::string input)
{
	std::ifstream file;

	file.open(input.c_str());
	if(!file.is_open())
		throw std::invalid_argument( RED "[ERROR] File not found" RESET);
	
	std::cout << MAGENTA << "Input file opened, converting data..." << RESET << std::endl;
	
	std::string line;
	std::getline(file, line);
	std::string key;
	std::string value;
	
	while (std::getline(file, line))
	{
		if(line.find("|") == std::string::npos)
		{
			std::cerr << ORANGE << "[ERROR] No value introduced" << RESET << std::endl;
			continue;
		}
		else
		{
			key = line.substr(0, line.find("|"));
			key = key.substr(0, key.find(" "));
			value = line.substr(line.find("|") + 1);
			value = value.substr(value.find(" ") + 1);
		}
		if(value.find("-") != std::string::npos)
		{
			std::cerr << ORANGE << "[ERROR] Negative value introduced" << RESET << std::endl;
			continue;
		}
		if(std::strtof(value.c_str(), NULL) > 1000)
		{
			std::cerr << ORANGE << "[ERROR] Value too high" << RESET << std::endl;
			continue;
		}
		_inputit = _data.lower_bound(key);
		if(_inputit == _data.end() || (_inputit != _data.begin() && _inputit->first != key))
			_inputit--;
		else if (_inputit != _data.begin() && (_inputit != _data.end() || _inputit->first != key))
		{
			std::map<std::string, float>::iterator tmp = _inputit;
			tmp--;
			if (_inputit == _data.end() || key.compare(_inputit->first) < _inputit->first.compare(key))
				_inputit = tmp;
		}
		std::cout << YELLOW;
		if(_inputit != _data.end())
			std::cout << key << " => " << value << " => " << _inputit->second * std::strtof(value.c_str(), NULL) << std::endl;
		else
			std::cout << key << " => " << value << " => " << "Unknown" << std::endl;
	}
	std::cout << RESET;
	file.close();
}
