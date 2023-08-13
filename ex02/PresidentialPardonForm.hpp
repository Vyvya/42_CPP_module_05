/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgejno <vgejno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 18:27:47 by vgejno            #+#    #+#             */
/*   Updated: 2023/08/13 19:35:21 by vgejno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"

#include <iostream>
#include <string>

class Bureaucrat;

class PresidentialPardonForm : public AForm {

	private:

		const std::string _PresidentialPardonFormName;
		const int _signGrade;
		const int _executeGrade;
		bool _PresidentialPardonFormSigned;

	public:
		
		PresidentialPardonForm();
		PresidentialPardonForm( const std::string PresidentialPardonFormName, int signGrade, int executeGrade );
		PresidentialPardonForm( const PresidentialPardonForm& other );
		virtual ~PresidentialPardonForm();

		PresidentialPardonForm& operator=( const PresidentialPardonForm& other );
		
		virtual std::string getPresidentialPardonFormName() const = 0;
		virtual int getPresidentialPardonFormSignGrade() const;
		virtual int getPresidentialPardonFormExecuteGrade() const;
		virtual int getPresidentialPardonFormSigned() const;
		
		bool beSigned( Bureaucrat& b );
		bool _checkPresidentialPardonFormSigned();
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

std::ostream &operator<<( std::ostream &os, const PresidentialPardonForm &instance );

#endif