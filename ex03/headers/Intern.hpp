/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgejno <vgejno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 21:26:24 by vgejno            #+#    #+#             */
/*   Updated: 2023/08/15 15:35:28 by vgejno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class AForm;
class ShrubberyCreationForm;

class Intern {

	public:

		Intern();
		~Intern();

		Intern( const Intern& other);
		Intern &operator=( const Intern& other );

		AForm* makeForm( std::string nameForm, std::string target );
};

std::ostream &operator<<( std::ostream &os, const Intern &instance );
