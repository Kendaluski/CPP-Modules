/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 10:07:03 by jjaen-mo          #+#    #+#             */
/*   Updated: 2024/11/07 11:26:27 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
 # define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <deque>
# include <cstdlib>
# include <algorithm>

# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define ORANGE "\033[38;5;214m"
# define CYAN "\033[92m"
# define MAGENTA "\033[35m"
# define BLACK "\033[30m"
# define BLUE "\033[34m"
# define RESET "\033[0m"

# define INS_THRESHOLD 10

class PmergeMe
{
	private:
		std::vector<int> _vector;
		std::deque<int> _deque;
	public:
		PmergeMe(int argc, char **argv);
		PmergeMe(const PmergeMe &pmergeme);
		~PmergeMe();
		PmergeMe & operator = (const PmergeMe &pmergeme);

		class NegativeNumberException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		void printVector(std::vector<int> vector);
		std::vector<int> getVector() const;
		std::vector<int> sortVector(std::vector<int> vector);
		void printDeque(std::deque<int> deque);
		std::deque<int> getDeque() const;
		std::deque<int> sortDeque(std::deque<int> deque);
};
 
std::ostream & operator << (std::ostream &out, const PmergeMe &pmergeme);
 
#endif