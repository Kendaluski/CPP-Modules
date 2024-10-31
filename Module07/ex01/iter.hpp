/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 09:42:54 by jjaen-mo          #+#    #+#             */
/*   Updated: 2024/10/31 09:49:16 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

	#include <iostream>
	#include <typeinfo>

	template <typename T>
	void iter(T *array, size_t size, void (*f)(T const &))
	{
		for (size_t i = 0; i < size; i++)
			f(array[i]);
	}
