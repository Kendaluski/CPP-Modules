/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:35:13 by jjaen-mo          #+#    #+#             */
/*   Updated: 2024/02/21 18:53:04 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <iostream>

namespace megaphone
{
	char *ft_to_upper(char *str)
	{
		int i = 0;
		while(str[i])
		{
			if(str[i] >= 'a' && str[i] <= 'z')
				str[i] -= 32;
			i++;
		}
		return (str);
	}
}

int main(int argc, char **argv)
{
	if(argc == 1)
		std::cout << " * LOUD AND UNBEARABLE FEEDBACK NOISE * " << std::endl;
	else
		{
			for(int i=1; i<argc; i++)
				std::cout <<  megaphone::ft_to_upper(argv[i]);
			std::cout << std::endl;
		}
	return (0);
}