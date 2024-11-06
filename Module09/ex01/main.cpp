/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 18:01:53 by jjaen-mo          #+#    #+#             */
/*   Updated: 2024/11/06 18:24:46 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN/RPN.hpp"

int main(int argc, char **argv)
{
	if(argc == 1)
	{
		std::cout << RED << "[ERROR] Usage: ./rpn [args]" << RESET << std::endl;
		return (1);
	}
	RPN rpn;
	
	rpn.fillStack(argc, argv);
	rpn.printStack();
	return (0);
}