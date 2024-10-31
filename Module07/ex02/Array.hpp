/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 09:48:38 by jjaen-mo          #+#    #+#             */
/*   Updated: 2024/10/31 10:05:16 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

	# include <iostream>
	# include <string>
	# include <sstream>
	# include <exception>
	

	# define RED "\033[31m"
	# define GREEN "\033[32m"
	# define ORANGE "\033[38;5;214m"
	# define MAGENTA "\033[35m"
	# define RESET "\033[0m"

	template <typename T>
	class Array
	{
		private:
			T *_array;
			size_t _size;
		public:
			Array(void);
			Array(unsigned int n);
			Array(Array const &src);
			~Array(void);
			
			Array &operator = (const Array &src);
			T &operator [] (size_t i);
			
			size_t size(void) const;
	};

	template <typename T>
	Array<T>::Array(void) : _array(NULL), _size(0) {};
	
	template <typename T>
	Array<T>::Array(unsigned int n) : _array(new T[n]), _size(n) {};

	template <typename T>
	Array<T>::Array(const Array &src) : _array(new T[src._size]), _size(src._size)
	{
		for(size_t i = 0; i < _size; i++)
			_array[i] = src._array[i];
	};

	template <typename T>
	Array<T>::~Array(void)
	{
		if (_array)
			delete [] _array;
	}

	template <typename T>
	Array<T> &Array<T>::operator = (const Array &src)
	{
		if (this != &src)
		{
			if (_array)
				delete [] _array;
			_array = new T[src._size];
			_size = src._size;
			for(size_t i = 0; i < _size; i++)
				_array[i] = src._array[i];
		}
		return *this;
	}

	template <typename T>
	T &Array<T>::operator [] (size_t i)
	{
		if (i >= _size)
			throw std::out_of_range(RED "[ERROR] Index out of range" RESET);
		return _array[i];
	}
	
	template <typename T>
	size_t Array<T>::size(void) const
	{
		return _size;
	}