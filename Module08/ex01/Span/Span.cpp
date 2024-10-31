/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 10:44:48 by jjaen-mo          #+#    #+#             */
/*   Updated: 2024/10/31 11:04:02 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
 
Span::Span(unsigned int n)
{
	std::cout << GREEN << "Span default constructor called" << RESET << std::endl;
	_size = n;
	_array.reserve(n);
}

Span::Span(const Span &span)
{
	std::cout << GREEN << "Span copy constructor called" << RESET << std::endl;
	*this = span;
}

Span::~Span()
{
	std::cout << RED << "Span destructor called" << RESET << std::endl;
	_array.clear();
}


void Span::addNumber(int n)
{
	if (_array.size() < _size)
		_array.push_back(n);
	else
		throw std::runtime_error(RED "[ERROR] Span is already full " RESET);
}


int Span::shortestSpan()
{
	if (_array.size() <= 1)
		throw std::runtime_error(RED "[ERROR] Span is empty or has only one element" RESET);
	
	std::vector<int> tmp = _array;
	std::sort(tmp.begin(), tmp.end());
	int min = tmp[1] - tmp[0];
	
	for(unsigned int i = 1; i < tmp.size(); i++)
	{
		if (tmp[i] - tmp[i - 1] < min)
			min = tmp[i] - tmp[i - 1];
	}
	return (min);
}

int Span::longestSpan()
{
	if(_array.size() <= 1)
		throw std::runtime_error(RED "[ERROR] Span is empty or has only one element" RESET);
		
	std::vector<int> tmp = _array;
	std::sort(tmp.begin(), tmp.end());
	return (tmp[tmp.size() - 1] - tmp[0]);
}

void Span::fillVector(void)
{
	for (unsigned int i = 0; i < _size; i++)
		_array.push_back(rand() % 1000000);
}

Span & Span::operator = (const Span &span)
{
	std::cout << GREEN << "Span copy operator called" << RESET << std::endl;
	_size = span._size;
	_array = span._array;
	return (*this);
}
 
std::ostream &operator<<(std::ostream &out, const Span &span)
{
	out << "Span [" << &span << "]";
	return (out);
}