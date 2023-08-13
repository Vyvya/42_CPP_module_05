/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgejno <vgejno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 14:47:21 by vgejno            #+#    #+#             */
/*   Updated: 2023/08/13 18:13:09 by vgejno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _formName("Unnamed"), _signGrade(1), _executeGrade(1), _formSigned(0) {
	
	std::cout << "Form constructor called" << std::endl;
}

Form::~Form() {
	
	std::cout << "Form " << this->_formName << " deconstructor called" << std::endl;
}

Form::Form( const std::string formName, int signGrade, int executeGrade ) \
	: _formName(formName),  _signGrade(signGrade), _executeGrade(executeGrade), _formSigned(false) {
	
	std::cout << "Form " << this->_formName << " signGrade " << this-> _signGrade \
		<< " executeGrade " << this-> _executeGrade << " constructor called" << std::endl;
	
	_checkGrade();
}

Form::Form( const Form& other ) : _formName(other._formName), _signGrade(other._signGrade), \
	_executeGrade(other._executeGrade), _formSigned(other._formSigned) {
		
	std::cout << "Copy constructor on Form " << other.getFormName() << " called" << std::endl;
}

Form& Form::operator=( const Form& other ) {

	if( this != &other ) {
		
		_formSigned = other._formSigned;
	}

	std::cout << "Copy assignement operator on Form " << other << " called" << std::endl;
	return *this;
}

bool Form::_checkGrade() {

	try {
		
		if( this->_signGrade < 1 || this->_executeGrade < 1) {

			throw Exception ("GradeTooLowException");
			return false;
		}	
			
		if( this->_signGrade > 150 || this->_executeGrade > 150) {

			throw Exception ("GradeTooHighException");
			return false;
		}
		
	} catch( Form::Exception& e ) {

		std::cout << "Form::" << e.getMessage() << std::endl;
	}
	return true;
}

bool Form::_checkFormSigned() {

	if ( this->_formSigned == true ) {

		return true;
	}
	return false;
}

std::string Form::getFormName() const{

	return this->_formName;
}

int Form::getFormSignGrade() const {

	return this-> _signGrade;
}

int Form::getFormExecuteGrade() const {

	return this-> _executeGrade;
}

int Form::getFormSigned() const {

	return this-> _formSigned;
}

bool Form::beSigned( Bureaucrat& b ) {
	
	if( (b.getGrade() <= this->getFormSignGrade()) && \
		( this->getFormExecuteGrade() >= 1 && this->getFormExecuteGrade() <= 150 ) \
			&& ( this->getFormSignGrade() >= 1 && this->getFormSignGrade() <= 150 ) ) {  

		this->_formSigned = true;
		
		return true;
	}
	
	return false;
}

Form::Exception::Exception( const std::string& msg ): _msg(msg) {
}

Form::Exception::~Exception() {
}

	std::string Form::Exception::getMessage() const {
	
	return this->_msg;
}

std::ostream &operator<<( std::ostream &os, const Form &instance ) {
	
	os << instance.getFormName() << " signGrade " << instance.getFormSignGrade() \
		<< " executeGrade " << instance.getFormExecuteGrade() << " is signed " << instance.getFormSigned();
	
	return os;
}