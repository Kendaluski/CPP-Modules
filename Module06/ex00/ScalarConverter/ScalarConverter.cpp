/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 16:13:28 by jjaen-mo          #+#    #+#             */
/*   Updated: 2024/11/05 17:32:10 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
 
ScalarConverter::ScalarConverter()
{
	std::cout << GREEN << "ScalarConverter default constructor called" << RESET << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &ScalarConverter)
{
	std::cout << "ScalarConverter copy constructor called" << std::endl;
	this->operator=(ScalarConverter);
}

ScalarConverter & ScalarConverter::operator = (const ScalarConverter &ScalarConverter)
{
	std::cout << "ScalarConverter copy operator called" << std::endl;
	if(this == &ScalarConverter)
		return (*this);
	this->ScalarConverter::operator=(ScalarConverter);
	return (*this);
}

ScalarConverter::~ScalarConverter()
{
	std::cout << ORANGE << "ScalarConverter destructor called" << RESET << std::endl;
}

ScalarConverter::ConvResult ScalarConverter::convert(std::string str)
{
	ConvResult result;
	char *endp;
	std::string str2;
	long i = 0;
	float f = 0.0f;
	double d = 0.0;
	
	result.c = '\0';
	result.i = 0;
	result.f = 0.0f;
	result.d = 0.0;
	
	if(!str.empty() && str[str.length() - 1] == 'f')
		str.erase(str.length() - 1);

	if(str.length() == 1 && std::isprint(str[0]) && !std::isdigit(str[0]))
		result.c = str[0];
	else
	{
		str2 = str;
		if(str2[0] == '+' || str2[0] == '-')
			str2.erase(0, 1);
		if(str2.find('.') != std::string::npos)
			str2.erase(str2.find('.'));
		i = std::strtol(str2.c_str(), &endp, 10);
		if (*endp == '\0' && i >= CHAR_MIN && i <= CHAR_MAX)
			result.c = static_cast<char>(i);
	}
	errno = 0;
	str2 = str;
	if(str2.find('.') != std::string::npos)
		str2.erase(str2.find('.'));
	i = std::strtol(str2.c_str(), &endp, 10);
	if (errno == ERANGE || i > INT_MAX || i < INT_MIN)
		std::cerr << RED << "[ERROR] Value out of range for int conversion" << RESET << std::endl;
	else if (*endp == '\0')
		result.i = static_cast<int>(i);

	if(str == "+inff")
	{
		result.f = INFINITY;
		result.d = INFINITY;
	}
	else if (str == "-inff")
	{
		result.f = -INFINITY;
		result.d = -INFINITY;
	}
	else if (str == "-inf")
	{
		result.f = -INFINITY;
		result.d = -INFINITY;
	}
	else if (str == "+inf")
	{
		result.f = INFINITY;
		result.d = INFINITY;
	}
	else if (str == "nanf" || str == "nan")
	{
		result.f = NAN;
		result.d = NAN;
	}
	else
	{
		errno = 0;
		f = std::strtof(str.c_str(), &endp);
		if (errno == ERANGE)
			std::cerr << RED << "[ERROR] Value out of range for float conversion" << RESET << std::endl;
		else if (*endp == '\0')
			result.f = f;
		
		errno = 0;
		d = std::strtod(str.c_str(), &endp);
		if (errno == ERANGE)
			std::cerr << RED << "[ERROR] Value out of range for double conversion" << RESET << std::endl;
		else if (*endp == '\0')
			result.d = d;
	}
	return (result);
}


std::ostream &operator<<(std::ostream &out, const ScalarConverter &ScalarConverter)
{
	out << "ScalarConverter " << &ScalarConverter;
	return (out);
}
