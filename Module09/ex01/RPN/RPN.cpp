/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 18:01:38 by jjaen-mo          #+#    #+#             */
/*   Updated: 2024/11/06 18:37:44 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
 
RPN::RPN()
{
	std::cout << GREEN << "RPN default constructor called" << RESET << std::endl;
}

RPN::RPN(const RPN &rpn)
{
	std::cout << "RPN copy constructor called" << std::endl;
	if(this != &rpn)
		*this = rpn;
}

RPN::~RPN()
{
	std::cout << RED << "RPN destructor called" << RESET << std::endl;
}

RPN & RPN::operator = (const RPN &rpn)
{
	std::cout << "RPN copy operator called" << std::endl;
	if (this != &rpn)
	{
		_stack = rpn._stack;
	}
	return (*this);
}
 
std::ostream &operator<<(std::ostream &out, const RPN &rpn)
{
	out << "RPN [" << &rpn << "]";
	return (out);
}

void RPN::printStack()
{
	std::stack<float> tmp = _stack;
	std::cout << CYAN << "Printing stack..." << RESET << std::endl;
	while (!tmp.empty())
	{
		std::cout << tmp.top() << std::endl;
		tmp.pop();
	}
}

float operate(float a, float b, char op)
{
	if (op == '+')
		return (a + b);
	if (op == '-')
		return (a - b);
	if (op == '*')
		return (a * b);
	if (op == '/')
		return (a / b);
	return (0);
}

void RPN::fillStack(int argc, char **argv)
{
	std::cout << MAGENTA << "Filling stack from input and calculating..." << RESET << std::endl;
	int i = 1;
	float a, b;
	
	
	while ( i < argc )
	{
		if(std::isdigit(*argv[argc]) == 0 || std::strlen(argv[argc]) > 1)
		{
			if(*argv[argc] != '+' && *argv[argc] != '-' && *argv[argc] != '*' && *argv[argc] != '/')
			{
				std::cout << RED << "[ERROR] Invalid input. Required numbers from 0 to 9 and + - * / operations" << RESET << std::endl;
				return;
			}
		}
		i++;
	}
}