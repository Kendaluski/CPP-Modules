/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 10:06:52 by jjaen-mo          #+#    #+#             */
/*   Updated: 2024/11/16 18:01:24 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe/PmergeMe.hpp"

int main(int argc, char **argv)
{
	if(argc < 2)
	{
		std::cout << RED << "[ERROR] Usage: ./pmergeme [args] " << RESET << std::endl;
		return (1);
	}
	PmergeMe pmergeme(argc, argv);
	
	std::vector<int> vector = pmergeme.getVector();
	
	if(pmergeme.getSize() <= 1)
	{
		return 0;
	}
	std::cout << GREEN << "Before: " << RESET;
	pmergeme.printVector(vector);
	std::cout << GREEN << "After: " << RESET;
	
	clock_t start, end;
	start = clock();
	vector = pmergeme.sortVector(pmergeme.getVector());
	end = clock();
	pmergeme.setVTime(static_cast<double>(end - start) / CLOCKS_PER_SEC);
	pmergeme.printVector(vector);
	pmergeme.sortDeque();
	
	std::cout << GREEN << "Time to process a range of " << vector.size() << " elements with std::vector : ";
	std::cout << RESET << ORANGE << pmergeme.getVTime() << " us" << RESET << std::endl;
	std::cout << GREEN << "Time to process a range of " << vector.size() << " elements with std::deque : ";
	std::cout << RESET << ORANGE << pmergeme.getDTime() << " us" << RESET << std::endl;
	return 0;
}