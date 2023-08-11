/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgejno <vgejno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 14:47:12 by vgejno            #+#    #+#             */
/*   Updated: 2023/08/11 19:49:42 by vgejno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

class Bureaucrat;

class Form {

	private:

		const std::string _formName;
		const int _signGrade;
		const int _executeGrade;
		bool _formSigned;
		
	public:
		
		Form();
		Form( const std::string formName, int signGrade, int executeGrade );
		Form( const Bureaucrat& other );
		~Form();

		Form& operator=( const Form& other );
		
		std::string getFormName() const;
		int getFormSignGrade() const;
		int getFormExecuteGrade() const;
		int getFormSigned() const;
		
		bool beSigned( Bureaucrat b );
		
		class Exception {

			private:

				std::string _msg;

			public:	
				
				Exception( const std::string& msg);
				~Exception();

			std::string getMessage() const;
				 
		};
		
};

std::ostream &operator<<( std::ostream &os, const Form &instance );

#endif