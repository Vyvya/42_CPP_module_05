/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgejno <vgejno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 18:27:26 by vgejno            #+#    #+#             */
/*   Updated: 2023/08/13 19:35:26 by vgejno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"

#include <iostream>
#include <string>

class Bureaucrat;

class RobotomyRequestForm : public AForm {

	private:

		const std::string _RobotomyRequestFormName;
		const int _signGrade;
		const int _executeGrade;
		bool _RobotomyRequestFormSigned;

	public:
		
		RobotomyRequestForm();
		RobotomyRequestForm( const std::string RobotomyRequestFormName, int signGrade, int executeGrade );
		RobotomyRequestForm( const RobotomyRequestForm& other );
		virtual ~RobotomyRequestForm();

		RobotomyRequestForm& operator=( const RobotomyRequestForm& other );
		
		virtual std::string getRobotomyRequestFormName() const = 0;
		virtual int getRobotomyRequestFormSignGrade() const;
		virtual int getRobotomyRequestFormExecuteGrade() const;
		virtual int getRobotomyRequestFormSigned() const;
		
		bool beSigned( Bureaucrat& b );
		bool _checkRobotomyRequestFormSigned();
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

std::ostream &operator<<( std::ostream &os, const RobotomyRequestForm &instance );

#endif