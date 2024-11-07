/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 10:07:06 by jjaen-mo          #+#    #+#             */
/*   Updated: 2024/11/07 11:26:41 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

const char *PmergeMe::NegativeNumberException::what() const throw()
{
	return ("[ERROR] Only positive numbers allowed");
}

PmergeMe::PmergeMe(int argc, char **argv)
{
	std::cout << GREEN << "PmergeMe default constructor called" << RESET << std::endl;
	
	std::cout << MAGENTA << "Filling vector and deque with arguments..." << RESET << RED << std::endl;
	for (int i = 1; i < argc; i++)
	{
		if (std::atoi(argv[i]) < 0)
			throw NegativeNumberException();
		_vector.push_back(std::atoi(argv[i]));
		_deque.push_back(std::atoi(argv[i]));
	}
	std::cout << RESET << MAGENTA << "Vector and deque filled" << RESET << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe &pmergeme)
{
	std::cout << "PmergeMe copy constructor called" << std::endl;
	if (this != &pmergeme)
	{
		*this = pmergeme;
	}
}

PmergeMe::~PmergeMe()
{
	std::cout << RED << "PmergeMe destructor called" << RESET << std::endl;
}

PmergeMe & PmergeMe::operator = (const PmergeMe &pmergeme)
{
	std::cout << "PmergeMe copy operator called" << std::endl;
	if (this != &pmergeme)
	{
		_vector = pmergeme._vector;
		_deque = pmergeme._deque;
	}
	return (*this);
}
 
std::ostream &operator<<(std::ostream &out, const PmergeMe &pmergeme)
{
	out << "PmergeMe [" << pmergeme << "]";
	return (out);
}


void PmergeMe::printVector(std::vector<int> vector)
{
	std::cout << ORANGE << "Vector: ";
	for (std::vector<int>::iterator it = vector.begin(); it != vector.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << RESET << std::endl;
}

static std::vector<int>	mergeVector(std::vector<int> l, std::vector<int> r)
{
	std::vector<int>	res;

	while (!l.empty() && !r.empty())
	{
		if (l[0] < r[0])
		{
			res.push_back(l[0]);
			l.erase(l.begin());
		}
		else
		{
			res.push_back(r[0]);
			r.erase(r.begin());
		}
	}

	while (!l.empty())
	{
		res.push_back(l[0]);
		l.erase(l.begin());
	}
	while (!r.empty())
	{
		res.push_back(r[0]);
		r.erase(r.begin());
	}
	return (res);	
}

std::vector<int> PmergeMe::sortVector(std::vector<int> vector)
{
	std::vector<int>	l;
	std::vector<int>	r;
	unsigned long int	m = vector.size() / 2;

	if (vector.size() <= 1)
		return (vector);
	for (unsigned long int i = 0; i < vector.size(); i++)
	{
		if (i < m)
			l.push_back(vector[i]);
		else
			r.push_back(vector[i]);
	}
	l = sortVector(l);
	r = sortVector(r);
	return(mergeVector(l, r));
}

std::vector<int> PmergeMe::getVector() const
{
	return (_vector);
}

void PmergeMe::printDeque(std::deque<int> deque)
{
	std::cout << ORANGE << "Deque: ";
	for (std::deque<int>::iterator it = deque.begin(); it != deque.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << RESET << std::endl;
}



