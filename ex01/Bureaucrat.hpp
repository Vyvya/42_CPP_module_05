/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgejno <vgejno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 18:01:45 by vgejno            #+#    #+#             */
/*   Updated: 2023/08/12 21:56:31 by vgejno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include "Form.hpp"

#define GR	"\033[38;5;118m"
#define OR	"\033[38;5;208m"
#define LB	"\033[38;5;39m"
#define VL	"\033[38;5;141m"
#define YL	"\033[38;5;226m"
#define RD	"\033[38;5;196m"
#define BL "\033[38;5;27m"
#define GN "\033[38;5;34m"
#define MAG "\033[38;5;161m"
#define LY	"\033[93m"
#define RS	"\033[0m"

class Form;

class Bureaucrat {

	private:

		const std::string _name;
		int _grade;

		void _checkGrade();
		
	public:
		
		Bureaucrat();
		Bureaucrat( const std::string name, int grade );
		Bureaucrat( const Bureaucrat& other );
		~Bureaucrat();

		Bureaucrat& operator=( const Bureaucrat& other );
		
		const std::string getName() const;
		int getGrade() const;
		void setGrade( const int grade );
		
		int incrementGrade();
		int decrementGrade();

		void signForm( Form& form );
		
		class Exception {

			private:

				std::string _msg;

			public:	
				
				Exception( const std::string& msg);
				~Exception();

			std::string getMessage() const;
				 
		};
		
};

std::ostream &operator<<( std::ostream &os, const Bureaucrat &instance );

#endif