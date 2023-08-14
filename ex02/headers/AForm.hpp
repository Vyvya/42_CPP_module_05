/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgejno <vgejno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 14:47:12 by vgejno            #+#    #+#             */
/*   Updated: 2023/08/13 18:34:00 by vgejno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include "Bureaucrat.hpp"

#include <iostream>
#include <string>

class Bureaucrat;

class AForm {

	private:

		const std::string _aformName;
		const int _signGrade;
		const int _executeGrade;
		bool _aformSigned;

	public:
		
		AForm();
		AForm( const std::string AformName, int signGrade, int executeGrade );
		AForm( const AForm& other );
		virtual ~AForm();

		AForm& operator=( const AForm& other );
		
		virtual bool execute(Bureaucrat const & executor) const = 0;
		
		std::string getAFormName() const;
		int getAFormSignGrade() const;
		int getAFormExecuteGrade() const;
		int getAFormSigned() const;
		
		bool beSigned( Bureaucrat& b );
		bool _checkAFormSigned() const;
		bool _checkGrade();
		
		class Exception {

			private:

				std::string _msg;

			public:	
				
				Exception( const std::string& msg);
				~Exception();

			std::string getMessage() const;
				 
		};
		
};

std::ostream &operator<<( std::ostream &os, const AForm &instance );

#endif
