/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 18:01:53 by jjaen-mo          #+#    #+#             */
/*   Updated: 2024/11/07 09:55:35 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN/RPN.hpp"

int getSize(char *str)
{
	char *tmp = new char[std::strlen(str) + 1];
	std::strcpy(tmp, str);
	int size = 0;
	char *tok = std::strtok(tmp, " ");
	
	while(tok != NULL)
	{
		size++;
		tok = std::strtok(NULL, " ");
	}
	delete[] tmp;
	return(size);
}

char **splitArgs(int size, char *str)
{
	char **args = new char *[size];
	char *tok, *tmp;
	int i = 0;


	tmp = str;
	tok = std::strtok(tmp, " ");
	while(tok != NULL)
	{
		args[i] = tok;
		tok = std::strtok(NULL, " ");
		i++;
	}
	
	return(args);
}

int main(int argc, char **argv)
{
	if(argc != 2)
	{
		std::cout << RED << "[ERROR] Usage: ./rpn " << '\"' << "[args]" << '\"' << RESET << std::endl;
		return (1);
	}
	
	int size = getSize(argv[1]);
	char **args = splitArgs(size, argv[1]);
	RPN rpn;

	if(rpn.fillStack(size, args))
		rpn.calculate();
	// rpn.printStack();
	delete [] args;
	return (0);
}