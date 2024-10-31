/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 09:28:05 by jjaen-mo          #+#    #+#             */
/*   Updated: 2024/10/31 09:43:51 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

	# include <iostream>
	# include <typeinfo>
	
	# define RED "\033[31m"
	# define GREEN "\033[32m"
	# define ORANGE "\033[38;5;214m"
	# define MAGENTA "\033[35m"
	# define RESET "\033[0m"
	
	template <typename T>
	void swap(T &a, T &b)
	{
		if(typeid(a) == typeid(b))
		{
			T tmp = a;
			a = b;
			b = tmp;
		}
		else
			std::cerr << RED << "[ERROR] Different types" << RESET << std::endl;
	}

	template <typename T>
	T min(T a, T b)
	{
		if(typeid(a) == typeid(b))
		{
			if(a < b)
				return a;
			else
				return b;
		}
		else
		{
			std::cerr << RED << "[ERROR] Different types" << RESET << std::endl;
			return 0;
		}
	}

	template <typename T>
	T max(T a, T b)
	{
		if(typeid(a) == typeid(b))
		{
			if(a > b)
				return a;
			else
				return b;
		}
		else
		{
			std::cerr << RED << "[ERROR] Different types" << RESET << std::endl;
			return 0;
		}
	}

#endif