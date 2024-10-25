/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 16:13:25 by jjaen-mo          #+#    #+#             */
/*   Updated: 2024/10/25 16:39:39 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter/ScalarConverter.hpp"

int main(int argc, char **argv)
{
	ScalarConverter scalarconverter;
	struct ScalarConverter::ConvResult result;

	if (argc != 2)
	{
		std::cerr << "Error: Invalid number of arguments" << std::endl;
		return (1);
	}
	result = ScalarConverter::convert(argv[1]);
	std::cout << "char: ";
	if (result.c == '\0')
		std::cout << "impossible" << std::endl;
	else if (std::isprint(result.c))
		std::cout << "'" << result.c << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
	std::cout << "int: ";
	if (result.i == 0)
		std::cout << "impossible" << std::endl;
	else
		std::cout << result.i << std::endl;
	std::cout << "float: ";
	if (result.f == 0.0f)
		std::cout << "impossible" << std::endl;
	else
		std::cout << result.f << "f" << std::endl;
	std::cout << "double: ";
	if (result.d == 0.0)
		std::cout << "impossible" << std::endl;
	else
		std::cout << result.d << std::endl;
	return (0);
}