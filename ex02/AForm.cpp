/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgejno <vgejno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 14:47:21 by vgejno            #+#    #+#             */
/*   Updated: 2023/08/13 18:36:37 by vgejno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
// #include "ShrubberyCreationForm.hpp"
// #include "RobotomyRequestForm.hpp"
// #include "PresidentialPardonForm.hpp"

AForm::AForm() : _aformName("Unnamed"), _signGrade(1), _executeGrade(1), _aformSigned(0) {
	
	std::cout << "AForm constructor called" << std::endl;
}

AForm::~AForm() {
	
	std::cout << "AForm " << this->_aformName << " deconstructor called" << std::endl;
}

AForm::AForm( const std::string AformName, int signGrade, int executeGrade ) \
	: _aformName(AformName),  _signGrade(signGrade), _executeGrade(executeGrade), _aformSigned(false) {
	
	std::cout << "AForm " << this->_aformName << " signGrade " << this-> _signGrade \
		<< " executeGrade " << this-> _executeGrade << " constructor called" << std::endl;
	
	_checkGrade();
}

AForm::AForm( const AForm& other ) : _aformName(other._aformName), _signGrade(other._signGrade), \
	_executeGrade(other._executeGrade), _aformSigned(other._aformSigned) {
		
	std::cout << "Copy constructor on AForm " << other.getAFormName() << " called" << std::endl;
}

AForm& AForm::operator=( const AForm& other ) {

	if( this != &other ) {
		
		_aformSigned = other._aformSigned;
	}

	std::cout << "Copy assignement operator on AForm " << other << " called" << std::endl;
	return *this;
}

bool AForm::_checkGrade() {

	try {
		
		if( this->_signGrade < 1 || this->_executeGrade < 1) {

			throw Exception ("GradeTooLowException");
			return false;
		}	
			
		if( this->_signGrade > 150 || this->_executeGrade > 150) {

			throw Exception ("GradeTooHighException");
			return false;
		}
		
	} catch( AForm::Exception& e ) {

		std::cout << "AForm::" << e.getMessage() << std::endl;
	}
	return true;
}

bool AForm::_checkAFormSigned() {

	if ( this->_aformSigned == true ) {

		return true;
	}
	return false;
}

std::string AForm::getAFormName() const{

	return this->_aformName;
}

int AForm::getAFormSignGrade() const {

	return this-> _signGrade;
}

int AForm::getAFormExecuteGrade() const {

	return this-> _executeGrade;
}

int AForm::getAFormSigned() const {

	return this-> _aformSigned;
}

bool AForm::beSigned( Bureaucrat& b ) {
	
	if( (b.getGrade() <= this->getAFormSignGrade()) && \
		( this->getAFormExecuteGrade() >= 1 && this->getAFormExecuteGrade() <= 150 ) \
			&& ( this->getAFormSignGrade() >= 1 && this->getAFormSignGrade() <= 150 ) ) {  

		this->_aformSigned = true;
		
		return true;
	}
	
	return false;
}

AForm::Exception::Exception( const std::string& msg ): _msg(msg) {
}

AForm::Exception::~Exception() {
}

	std::string AForm::Exception::getMessage() const {
	
	return this->_msg;
}

std::ostream &operator<<( std::ostream &os, const AForm &instance ) {
	
	os << instance.getAFormName() << " signGrade " << instance.getAFormSignGrade() \
		<< " executeGrade " << instance.getAFormExecuteGrade() << " is signed " << instance.getAFormSigned();
	
	return os;
}