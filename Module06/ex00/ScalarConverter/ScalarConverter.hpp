/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 16:13:30 by jjaen-mo          #+#    #+#             */
/*   Updated: 2024/10/31 08:50:00 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
 # define SCALARCONVERTER_HPP

# include <iostream>
# include <cstdlib>
# include <cerrno>
# include <cctype>
# include <string>
# include <math.h>
# include <cmath>
# include <climits>
# include <iomanip>

# define RED "\033[31m"
# define GREEN "\033[32m"
# define ORANGE "\033[38;5;214m"
# define MAGENTA "\033[35m"
# define RESET "\033[0m"

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &ScalarConverter);
	public:
		ScalarConverter & operator = (const ScalarConverter &ScalarConverter);
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

std::ostream & operator << (std::ostream &out, const ScalarConverter &ScalarConverter);

#endif