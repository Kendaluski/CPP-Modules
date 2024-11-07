/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 18:01:38 by jjaen-mo          #+#    #+#             */
/*   Updated: 2024/11/07 09:55:12 by jjaen-mo         ###   ########.fr       */
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
	std::cout << CYAN << "Printing stack..." << std::endl;
	while (!tmp.empty())
	{
		if(tmp.top() == PMASK)
			std::cout << "+" << std::endl;
		else if(tmp.top() == SMASK)
			std::cout << "-" << std::endl;
		else if(tmp.top() == MMASK)
			std::cout << "*" << std::endl;
		else if(tmp.top() == DMASK)
			std::cout << "/" << std::endl;
		else
			std::cout << tmp.top() << std::endl;
		tmp.pop();
	}
	std::cout << RESET;
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

bool RPN::fillStack(int argc, char **argv)
{
	std::cout << MAGENTA << "Filling stack from input..." << RESET << std::endl;
	
	argc--;
	while ( argc >= 0 )
	{
		if(std::isdigit(*argv[argc]) == 0 || std::strlen(argv[argc]) > 1)
		{
			if(*argv[argc] != '+' && *argv[argc] != '-' && *argv[argc] != '*' && *argv[argc] != '/')
			{
				std::cout << RED << "[ERROR] Invalid input. Required numbers from 0 to 9 and + - * / operations" << RESET << std::endl;
				return (false);
			}
			if(*argv[argc] == '+')
				_stack.push(PMASK);
			else if(*argv[argc] == '-' )
				_stack.push(SMASK);
			else if(*argv[argc] == '*')
				_stack.push(MMASK);
			else if(*argv[argc] == '/')
				_stack.push(DMASK);		
		}
		else
			_stack.push(std::strtof(argv[argc], NULL));
		argc--;
	}
	std::cout << MAGENTA << "Stack filled" << RESET << std::endl;
	return (true);
}

float RPN::operate(float a, float b, float op)
{
	if (op == PMASK)
		return (a + b);
	if (op == SMASK)
		return (a - b);
	if (op == MMASK)
		return (a * b);
	if (op == DMASK)
		return (a / b);
	return (0);
}

void RPN::calculate()
{
	float a,b, tmp;

	if(_stack.size() < 3)
	{
		std::cerr << RED << "[ERROR] Not enough elements to execute operations" << RESET << std::endl;
		return;
	}
	if(_stack.top() == PMASK || _stack.top() == SMASK || _stack.top() == MMASK || _stack.top() == DMASK)
	{
		std::cerr << RED << "[ERROR] Invalid input. Required at least 2 numbers from 0 to 9 and + - * / operations" << RESET << std::endl;
		return;
	}
	a = _stack.top();
	_stack.pop();
	b = _stack.top();
	_stack.pop();
	if(b == PMASK || b == SMASK || b == MMASK || b == DMASK)
	{
		std::cerr << RED << "[ERROR] Invalid input. Required at least 2 numbers from 0 to 9 and + - * / operations" << RESET << std::endl;
		return;
	}
	std::cout << YELLOW << "Calculating..." << RESET << std::endl;
	_result = operate(a, b, _stack.top());
	if(_stack.size() == 1)
	{
		std::cout << GREEN << "Result: " << _result << RESET << std::endl;
		return;
	}
	_stack.pop();
	a = _stack.top();
	if(a == PMASK || a == SMASK || a == MMASK || a == DMASK)
	{
		std::cerr << RED << "[ERROR] Invalid input. Required at least 1 number between operations" << RESET << std::endl;
		return;
	}
	_stack.pop();
	while(!_stack.empty())
	{
		if(_stack.top() == PMASK || _stack.top() == SMASK || _stack.top() == MMASK || _stack.top() == DMASK)
		{
			_result = operate(_result, a, _stack.top());
			_stack.pop();
			if(_stack.empty())
				break;
			a = _stack.top();
			_stack.pop();
		}
		else
		{
			b = _stack.top();
			_stack.pop();
			tmp = operate(a, b, _stack.top());
			_stack.pop();
			_result = operate(_result, tmp, _stack.top());
			_stack.pop();
			if(_stack.empty())
				break;
			a = _stack.top();
			_stack.pop();
		}
	}
	std::cout << GREEN << "Result: " << _result << RESET << std::endl;
}