/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 08:50:33 by jjaen-mo          #+#    #+#             */
/*   Updated: 2024/10/01 09:18:46 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
 # define FORM_HPP

# include <iostream>
# include "../Bureaucrat/Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string _name;
		bool _signed;
		const int _gradeToSign;
		const int _gradeToExecute;
	public:
		Form();
		Form(const Form &form);
		Form(std::string name, int gradeToSign, int gradeToExecute);
		Form(std::string name);
		Form(int gradeToSign, int gradeToExecute);
		~Form();
		std::string getName() const;
		bool getSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;
		void beSigned(Bureaucrat &bureaucrat);
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		Form & operator = (const Form &form);
};
 
std::ostream & operator << (std::ostream &out, const Form &form);
 
#endif