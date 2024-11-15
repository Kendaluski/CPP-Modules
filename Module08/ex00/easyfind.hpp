/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 10:13:35 by jjaen-mo          #+#    #+#             */
/*   Updated: 2024/11/15 16:59:35 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

	# include <iostream>
	# include <algorithm>
	# include <typeinfo>
	# include <vector>
	
	# define RED "\033[31m"
	# define GREEN "\033[32m"
	# define ORANGE "\033[38;5;214m"
	# define MAGENTA "\033[35m"
	# define RESET "\033[0m"
	
	template <typename T>
	void easyfind(T container, int value)
	{
		if(typeid(typename T::value_type) != typeid(int))
		{
			std::cout << RED << "Error: The container must be of type int" << RESET << std::endl;
			return;
		}
		
		typename T::iterator it = std::find(container.begin(), container.end(), value);
		
		if (it != container.end())
			std::cout << GREEN << "Value " << value << " found" << RESET << std::endl;
		else
			std::cout << RED << "Value " << value << " not found" << RESET << std::endl;
	}