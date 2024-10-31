/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 10:37:54 by jjaen-mo          #+#    #+#             */
/*   Updated: 2024/10/31 11:04:21 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Span/Span.hpp"

int main()
{
	Span sp = Span(5);
	Span sp2 = Span(10000);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << MAGENTA << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << RESET << std::endl;
	sp2.fillVector();
	std::cout << MAGENTA << sp2.shortestSpan() << std::endl;
	std::cout << sp2.longestSpan() << RESET << std::endl;
	return 0;
}