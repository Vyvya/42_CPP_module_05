/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgejno <vgejno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 18:51:16 by vgejno            #+#    #+#             */
/*   Updated: 2023/08/15 17:07:14 by vgejno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/RobotomyRequestForm.hpp"
#include "headers/Bureaucrat.hpp"

#include <ctime>
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm()  : AForm() {

	// std::cout << "RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm( std::string target ) : AForm(target, 72, 45) {

	std::cout << "RobotomyRequestForm " << this->getAFormName() << " signGrade " 
		<< this->getAFormSignGrade() << " executeGrade " << this->getAFormExecuteGrade() 
			<< " constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {

	std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

void RobotomyRequestForm::drillForm() const {
	
	srand(time(0));

	int randomValue = rand() % 2;
	
	if( randomValue == 0 ) {
		
		std::cout << "BZRZRZRRZRZRZRR" << std::endl;
	} else{

		std::cout << "krtkrktkrkkrktkrk" << std::endl;
	}
}

bool RobotomyRequestForm::execute(Bureaucrat const & executor) const {

	try {
		
		if( ( executor.getGrade() <= this->getAFormExecuteGrade()) && this->_checkAFormSigned() == true ) {
			
			drillForm();
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

		std::cout << "RobotomyRequestForm::" << e.getMessage() << std::endl;
	}
	return false;
}