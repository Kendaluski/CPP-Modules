/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 10:44:48 by jjaen-mo          #+#    #+#             */
/*   Updated: 2024/11/15 16:53:05 by jjaen-mo         ###   ########.fr       */
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
	
	std::vector<int> diffs(tmp.size() - 1);
	std::adjacent_difference(tmp.begin(), tmp.end(), diffs.begin());
	diffs.erase(diffs.begin());
	
	return (std::min_element(diffs.begin(), diffs.end())[0]);
}

int Span::longestSpan()
{
	if(_array.size() <= 1)
		throw std::runtime_error(RED "[ERROR] Span is empty or has only one element" RESET);
		
	std::pair<std::vector<int>::iterator, std::vector<int>::iterator> res;
	res.first = std::min_element(_array.begin(), _array.end());
	res.second = std::max_element(_array.begin(), _array.end());
	return (*res.second - *res.first);
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