/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgejno <vgejno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 18:27:26 by vgejno            #+#    #+#             */
/*   Updated: 2023/08/14 22:25:41 by vgejno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"

#include <iostream>
#include <string>

class Bureaucrat;

class RobotomyRequestForm : public AForm {

	private:

		void drillForm() const;

	public:
		
		RobotomyRequestForm();
		RobotomyRequestForm( std::string target );
		~RobotomyRequestForm();
		
		bool execute(Bureaucrat const & executor) const;
		
};

#endif 