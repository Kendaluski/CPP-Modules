/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 18:01:37 by jjaen-mo          #+#    #+#             */
/*   Updated: 2024/11/07 09:54:49 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
 # define RPN_HPP

# include <iostream>
# include <stack>
# include <cstdlib>
# include <cstring>

# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define ORANGE "\033[38;5;214m"
# define CYAN "\033[92m"
# define MAGENTA "\033[35m"
# define BLACK "\033[30m"
# define BLUE "\033[34m"
# define RESET "\033[0m"

# define PMASK 4194304
# define SMASK 8388608
# define MMASK 16777216
# define DMASK 33554432

class RPN
{
	private:
		std::stack<float> _stack;
		float _result;
	public:
		RPN();
		RPN(const RPN &rpn);
		~RPN();
		RPN & operator = (const RPN &rpn);

		bool fillStack(int argc, char **argv);
		void printStack();
		void calculate();
		float operate(float a, float b, float op);
};
 
std::ostream & operator << (std::ostream &out, const RPN &rpn);
 
#endif