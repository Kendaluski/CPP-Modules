/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 22:21:11 by jjaen-mo          #+#    #+#             */
/*   Updated: 2024/03/19 22:35:26 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string *strPTR = &str;
	std::string &strREF = str;

	std::cout << "String Memory Address:	  " << &str << std::endl;
	std::cout << "StringPTR Memory Address: " << strPTR << std::endl;
	std::cout << "StringREF Memory Address: " << &strREF << std::endl;
	std::cout << "String Value:		" << str << std::endl;
	std::cout << "StringPTR Value:	" << *strPTR << std::endl;
	std::cout << "StringREF Value:	" << strREF << std::endl;
	return (0);
}
