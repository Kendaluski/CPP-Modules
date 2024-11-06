/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:13:23 by jjaen-mo          #+#    #+#             */
/*   Updated: 2024/11/05 17:58:56 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
 # define MUTANTSTACK_HPP

# include <iostream>
# include <stack>
# include <typeinfo>
# include <list>

# define RESET   "\033[0m"
# define MAGENTA "\033[35m"
# define ORANGE  "\033[33m"

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		typedef typename std::stack<T>::container_type::iterator iterator;
		
		MutantStack();
		MutantStack(const MutantStack &mutantstack);
		~MutantStack();
		MutantStack &operator=(const MutantStack &mutantstack);

		iterator begin();
		iterator end();
};
 
template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>() {}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack &mutantstack) : std::stack<T>(mutantstack) {}

template <typename T>
MutantStack<T>::~MutantStack() {}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack &mutantstack)
{
	if (this == &mutantstack)
		return *this;
	std::stack<T>::operator=(mutantstack);
	return *this;
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin() { return std::stack<T>::c.begin();}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end() { return std::stack<T>::c.end();}

#endif