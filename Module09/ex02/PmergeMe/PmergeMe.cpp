/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 10:07:06 by jjaen-mo          #+#    #+#             */
/*   Updated: 2024/11/11 12:11:50 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

const char *PmergeMe::NegativeNumberException::what() const throw()
{
	return ("[ERROR] Only positive numbers allowed");
}

const char *PmergeMe::CharException::what() const throw()
{
	return ("[ERROR] Only numbers allowed");
}

const char *PmergeMe::DuplicateException::what() const throw()
{
	return ("[ERROR] Duplicate numbers not allowed");
}

bool	thereAreChar(char *str)
{
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] < '0' || str[i] > '9')
		{
			if(str[i] == '-')
				continue;
			return (true);
		}
	}
	return (false);
}

bool	thereAreDuplicates(std::vector<int> vector)
{
	std::sort(vector.begin(), vector.end());
	for (unsigned long int i = 0; i < vector.size() - 1; i++)
	{
		if (vector[i] == vector[i + 1])
			return (true);
	}
	return (false);
}

PmergeMe::PmergeMe(int argc, char **argv)
{
	std::cout << GREEN << "PmergeMe default constructor called" << RESET << std::endl;
	std::cout << MAGENTA << "Filling vector and deque with arguments..." << RESET << RED << std::endl;
	for (int i = 1; i < argc; i++)
	{
		if (thereAreChar(argv[i]) == true)
			throw CharException();
		if (std::atoi(argv[i]) < 0)
			throw NegativeNumberException();
		_vector.push_back(std::atoi(argv[i]));
		_deque.push_back(std::atoi(argv[i]));
	}
	if (thereAreDuplicates(_vector) == true)
		throw DuplicateException();
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

PmergeMe &PmergeMe::operator=(const PmergeMe &pmergeme)
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
	std::cout << ORANGE;
	for (std::vector<int>::iterator it = vector.begin(); it != vector.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << RESET << std::endl;
}

static std::vector<int> mergeVector(std::vector<int> l, std::vector<int> r)
{
	std::vector<int> res;
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
	unsigned long int	m;

	std::vector<int> l;
	std::vector<int> r;
	m = vector.size() / 2;
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
	return (mergeVector(l, r));
}

std::vector<int> PmergeMe::getVector() const
{
	return (_vector);
}

void PmergeMe::printDeque()
{
	std::cout << ORANGE;
	for (std::deque<int>::iterator it = _deque.begin(); it != _deque.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << RESET << std::endl;
}

void	merge(std::deque<int> &deque, int l, int m, int r)
{
	int	n1;
	int	n2;
	int	i = 0, j = 0, k;

	n1 = m - l + 1;
	n2 = r - m;
	std::deque<int> L(n1);
	std::deque<int> R(n2);
	std::copy(deque.begin() + l, deque.begin() + m + 1, L.begin());
	std::copy(deque.begin() + m + 1, deque.begin() + r + 1, R.begin());
	i = 0, j = 0, k = l;
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			deque[k] = L[i];
			i++;
		}
		else
		{
			deque[k] = R[j];
			j++;
		}
		k++;
	}
	while (i < n1)
	{
		deque[k] = L[i];
		i++;
		k++;
	}
	while (j < n2)
	{
		deque[k] = R[j];
		j++;
		k++;
	}
}

void	insertionSort(std::deque<int> &deque, int l, int r)
{
	int i, j, key;
	for (i = l + 1; i <= r; i++)
	{
		key = deque[i];
		j = i - 1;
		while (j >= l && deque[j] > key)
		{
			deque[j + 1] = deque[j];
			j--;
		}
		deque[j + 1] = key;
	}
}

void	mergeInsertSort(std::deque<int> &deque, int l, int r)
{
	int	m;

	if (l < r)
	{
		if (r - l + 1 <= INS_THRESHOLD)
			insertionSort(deque, l, r);
		else
		{
			m = l + (r - l) / 2;
			mergeInsertSort(deque, l, m);
			mergeInsertSort(deque, m + 1, r);
			merge(deque, l, m, r);
		}
	}
}

void PmergeMe::sortDeque()
{
	clock_t start, end;
	start = clock();
	mergeInsertSort(_deque, 0, _deque.size() - 1);
	end = clock();
	_dTime = static_cast<double>(end - start) / CLOCKS_PER_SEC;
}

std::deque<int> PmergeMe::getDeque() const
{
	return (_deque);
}

double PmergeMe::getVTime() const
{
	return (_vTime);
}

double PmergeMe::getDTime() const
{
	return (_dTime);
}

void PmergeMe::setVTime(double vTime)
{
	_vTime = vTime;
}
