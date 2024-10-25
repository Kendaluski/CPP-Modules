/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 16:13:30 by jjaen-mo          #+#    #+#             */
/*   Updated: 2024/10/25 16:48:42 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
 # define SCALARCONVERTER_HPP

# include <iostream>
# include <sstream>
# include <stdexcept>
# include <cctype>
# include <string>

class ScalarConverter
{
	private:
	public:
		ScalarConverter();
		~ScalarConverter();
		
		struct ConvResult
		{
			char c;
			int i;
			float f;
			double d;
		};
		
		static ScalarConverter::ConvResult convert(std::string str);
};
 
std::ostream & operator << (std::ostream &out, const ScalarConverter &scalarconverter);
 
#endif