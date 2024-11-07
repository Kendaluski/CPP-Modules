/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 10:06:52 by jjaen-mo          #+#    #+#             */
/*   Updated: 2024/11/07 11:25:09 by jjaen-mo         ###   ########.fr       */
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
	
	vector = pmergeme.sortVector(pmergeme.getVector());
	pmergeme.printVector(vector);
	return 0;
}