/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgejno <vgejno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 18:27:47 by vgejno            #+#    #+#             */
/*   Updated: 2023/08/14 22:27:39 by vgejno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "Bureaucrat.hpp"
#include "AForm.hpp"

#include <iostream>
#include <string>

class Bureaucrat;

class PresidentialPardonForm : public AForm {

	private:

		void pardonForm() const;

	public:
		
		PresidentialPardonForm();
		PresidentialPardonForm( std::string target );
		~PresidentialPardonForm();

		bool execute(Bureaucrat const & executor) const;

};

#endif