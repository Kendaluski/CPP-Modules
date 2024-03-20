/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 02:21:25 by jjaen-mo          #+#    #+#             */
/*   Updated: 2024/03/20 02:58:50 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"

void replace(std::string filename, std::string s1, std::string s2)
{
	std::fstream file;
	std::string line;
	std::string result;
	
	file.open(filename, std::fstream::in);
	if (!file.is_open())
	{
		std::cerr << "[ERROR] File not found / unable to open" << std::endl;
		return ;
	}
	while(std::getline(file, line))
	{
		while (line.find(s1) != std::string::npos)
		{
			result += line.substr(0, line.find(s1));
			result += s2;
			line.erase(0, line.find(s1) + s1.length());
		}
	}
	if (result.empty())
	{
		std::cerr << "[ERROR] No matches found" << std::endl;
		return ;
	}
	file.close();
	file.open(filename + ".replace", std::fstream::out);
	if (!file.is_open())
	{
		std::cerr << "[ERROR] Unable to create file" << std::endl;
		return ;
	}
	file << result << std::endl;
	file.close();
}

int main(int argc, char **argv)
{
	std::string filename;
	std::string s1;
	std::string s2;
	
	if (argc != 4)
	{
		std::cerr << "Error: Invalid number of arguments" << std::endl;
		return (1);
	}
	filename = argv[1];
	s1 = argv[2];
	s2 = argv[3];
	if (s1.empty() || s2.empty() || filename.empty())
	{
		std::cerr << "[ERROR] No empty values accepted" << std::endl;
		return (1);
	}
	replace(filename, s1, s2);
	return (0);
}