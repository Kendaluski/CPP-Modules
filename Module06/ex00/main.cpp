/* ************************************************************************** */ /*                                                                            */
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
	struct ScalarConverter::ConvResult result;

	if (argc != 2)
	{
		std::cerr << RED << "Error: Invalid number of arguments" << RESET << std::endl;
		return (1);
	}
	result = ScalarConverter::convert(argv[1]);

	std::cout << MAGENTA << "char: ";
	if (result.c == '\0')
		std::cout << RESET << RED << "impossible" << RESET << MAGENTA << std::endl;
	else if (std::isprint(result.c))
		std::cout << "'" << result.c << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
	
	std::cout << "int: ";
	if (std::isnan(result.d) || std::isinf(result.d))
		std::cout << RESET << RED  << "impossible" << RESET << MAGENTA << std::endl;
	else
		std::cout << result.i << std::endl;
	
	std::cout << "float: ";
	std::cout << std::fixed << std::setprecision(1) << result.f << "f" << std::endl;

	std::cout << "double: ";
	std::cout << std::fixed << std::setprecision(1) << result.d << RESET << std::endl;
	return (0);
}