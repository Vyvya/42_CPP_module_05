/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgejno <vgejno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 18:26:50 by vgejno            #+#    #+#             */
/*   Updated: 2023/08/14 22:19:23 by vgejno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"

#include <iostream>
#include <string>
#include <fstream> 

class Bureaucrat;

class ShrubberyCreationForm : public AForm {

	private:

		void _formTree(void) const;
		
	public:
		
		ShrubberyCreationForm();
		ShrubberyCreationForm( std::string target );
		~ShrubberyCreationForm();
		
		bool execute(Bureaucrat const & executor) const;
		
		class ExceptionFile {

			private:

				std::string _msg;

			public:	
				
				ExceptionFile( const std::string& msg);
				~ExceptionFile();

			std::string getMessage() const;
				 
		};
		
};

#endif