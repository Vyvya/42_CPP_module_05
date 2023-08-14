/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgejno <vgejno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 18:27:55 by vgejno            #+#    #+#             */
/*   Updated: 2023/08/14 21:15:43 by vgejno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/Bureaucrat.hpp"
#include "headers/PresidentialPardonForm.hpp"

#include <ctime>
#include <cstdlib>

PresidentialPardonForm::PresidentialPardonForm( std::string target ) : AForm(target, 25, 5) {

	std::cout << "PresidentialPardonForm " << this->getAFormName() << " signGrade " \
		<< this->getAFormSignGrade() << " executeGrade " << this->getAFormExecuteGrade() \
			<< " constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {

	std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

void PresidentialPardonForm::pardonForm() const {

	std::cout << this->getAFormName() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

bool PresidentialPardonForm::execute(Bureaucrat const & executor) const {

	try {
		
		if( ( executor.getGrade() <= this->getAFormExecuteGrade()) && this->_checkAFormSigned() == true ) {
			
			pardonForm();
			return true;

		} else {

			if( executor.getGrade() > this->getAFormExecuteGrade() ) {
				
				throw AForm::Exception("executor has wrong permissions");
			} else if( this->_checkAFormSigned() == false ) {
				
				throw AForm::Exception("form wasn't signed");
			} else {
				
				throw AForm::Exception("executor and form are not coordinated");
			}
		}
		
	} catch ( const AForm::Exception& e ) {

		std::cout << "PresidentialPardonForm::" << e.getMessage() << std::endl;
	}
	return false;
}
