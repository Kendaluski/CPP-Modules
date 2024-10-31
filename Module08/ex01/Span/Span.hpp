/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 10:44:46 by jjaen-mo          #+#    #+#             */
/*   Updated: 2024/10/31 11:00:10 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
 # define SPAN_HPP

# include <iostream>
# include <vector>
# include <exception>
# include <algorithm>

# define RED "\033[31m"
# define GREEN "\033[32m"
# define ORANGE "\033[38;5;214m"
# define MAGENTA "\033[35m"
# define RESET "\033[0m"

class Span
{
	private:
		std::vector<int> _array;
		unsigned int _size;
	public:
		Span(unsigned int n);
		Span(const Span &span);
		~Span();
		Span & operator = (const Span &span);

		void addNumber(int n);
		int shortestSpan();
		int longestSpan();
		void fillVector(void);
};
 
std::ostream & operator << (std::ostream &out, const Span &span);
 
#endif