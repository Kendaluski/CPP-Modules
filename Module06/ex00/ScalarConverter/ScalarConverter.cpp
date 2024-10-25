/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 16:13:28 by jjaen-mo          #+#    #+#             */
/*   Updated: 2024/10/25 16:51:06 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
 
ScalarConverter::ScalarConverter()
{
	std::cout << "ScalarConverter default constructor called" << std::endl;
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "ScalarConverter destructor called" << std::endl;
}

ScalarConverter::ConvResult ScalarConverter::convert(std::string str)
{
	ConvResult result;
	
	result.c = '\0';
	result.i = 0;
	result.f = 0.0f;
	result.d = 0.0;
	
	if(str.length() == 1 && std::isprint(str[0]) && !std::isdigit(str[0]))
		result.c = str[0];
	
	try {
		size_t pos = 0;

		std::istringstream is
		if(pos == str.length())
		{
			result.f = static_cast<float>(result.i);
			result.d = static_cast<double>(result.i);
			return (result);
		}
	} catch (const std::invalid_argument &e) {
		std::cerr << "Invalid argument: " << e.what() << std::endl;
	} catch (const std::out_of_range &e) {
		std::cerr << "Out of range for int value: " << e.what() << std::endl;
	}

	try{
		size_t pos;
		result.f = std::stof(str, &pos);
		if(pos == str.length())
		{
			result.i = static_cast<int>(result.f);
			result.d = static_cast<double>(result.f);
			return (result);
		}
	} catch (const std::invalid_argument &e) {
		std::cerr << "Invalid argument: " << e.what() << std::endl;
	} catch (const std::out_of_range &e) {
		std::cerr << "Out of range for float value: " << e.what() << std::endl;
	}

	try {
		size_t pos;
		result.d = std::stod(str, &pos);
		if(pos == str.length())
		{
			result.i = static_cast<int>(result.d);
			result.f = static_cast<float>(result.d);
			return (result);
		}
	} catch (const std::invalid_argument &e) {
		std::cerr << "Invalid argument: " << e.what() << std::endl;
	} catch (const std::out_of_range &e) {
		std::cerr << "Out of range for double value: " << e.what() << std::endl;
	}
	return (result);
}

std::ostream &operator<<(std::ostream &out, const ScalarConverter &scalarconverter)
{
	out << "ScalarConverter [" << &scalarconverter << "]";
	return (out);
}