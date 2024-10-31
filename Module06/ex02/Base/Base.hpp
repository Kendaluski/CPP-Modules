/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 08:59:00 by jjaen-mo          #+#    #+#             */
/*   Updated: 2024/10/31 09:20:08 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
 # define BASE_HPP

# include <iostream>
# include <ctime>
# include <cstdlib>
# include <typeinfo>

# define RED "\033[31m"
# define GREEN "\033[32m"
# define ORANGE "\033[38;5;214m"
# define MAGENTA "\033[35m"
# define RESET "\033[0m"

class Base
{
	public:
		virtual ~Base();
};

class A : public Base {};
class B : public Base {};
class C : public Base {};

Base * generate(void);
void identify(Base *p);
void identify(Base &p);
 
#endif