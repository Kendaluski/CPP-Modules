/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 09:15:42 by jjaen-mo          #+#    #+#             */
/*   Updated: 2024/10/31 09:16:58 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base/Base.hpp"

int main(void)
{
	Base *base = generate();
	identify(base);
	identify(*base);
	delete base;
	return (0);
}