/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgejno <vgejno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 18:01:58 by vgejno            #+#    #+#             */
/*   Updated: 2023/08/13 18:23:51 by vgejno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat() {
	
	std::cout << "Bureaucrat constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat() {
	
	std::cout << "Bureaucrat " << this->_name << " deconstructor called" << std::endl;
}

Bureaucrat::Bureaucrat( const std::string name, int grade ) : _name(name), _grade(grade) {
	
	std::cout << "Bureaucrat " << this->_name << " grade " << this->_grade << " constructor called" << std::endl;
	
	this->_checkGrade();
}

Bureaucrat::Bureaucrat( const Bureaucrat& other ) : _name( other._name ) {

	this->_grade = other._grade;
	std::cout << "Copy constructor on Bureaucrat " << other << " called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=( const Bureaucrat& other ) {

	if( this != &other ) {
		
		this->_grade = other._grade;
	}

	std::cout << "Copy assignement operator on Bureaucrat " << other << " called" << std::endl;
	return *this;
}

bool Bureaucrat::_checkGrade() {

	try {
		
		if( this->_grade < 1 ) {

			throw Exception ("GradeTooLowException");
			return false;
		}	
			
		if( this->_grade > 150 ) {

			throw Exception ("GradeTooHighException");
			return false;

		}
		
	} catch( Bureaucrat::Exception& e ) {

		std::cout << "Bureaucrat::" << e.getMessage() << std::endl;
	}
	return true;

}

const std::string Bureaucrat::getName() const{

	return this->_name;
}

int Bureaucrat::getGrade() const {

	return this->_grade;
}

void Bureaucrat::setGrade( const int grade ) {

	this->_grade = grade;
}

int Bureaucrat::incrementGrade() {

	_grade--;
	
	this->_checkGrade();
	std::cout << "Bureaucrat " << this->_name << " increment grade to " << this->_grade << std::endl;

	return _grade;
}

int Bureaucrat::decrementGrade() {

	_grade++;

	this->_checkGrade();
	std::cout << "Bureaucrat " << this->_name << " decrement grade to " << this->_grade << std::endl;
	
	return _grade;
}

void Bureaucrat::signForm( Form& form ) {

	try {
		
		if ( form._checkFormSigned() == true ) {
			
    		std::cout << getName() << " signed " << form.getFormName() << std::endl; 
			
		} else {
			
			if( this->getGrade() < 1 || this->getGrade() > 150 )  {

				throw Exception ("1bureaucrat has wrong permissions");
				
			} else if( (form.getFormExecuteGrade() < 1 || form.getFormExecuteGrade() > 150) \
				|| (form.getFormSignGrade() < 1 || form.getFormSignGrade() > 150) ) {

				throw Exception ("form is falsely configured");
			}
			else
				throw Exception ("bureaucrat has wrong permissions");
		}
        
    } catch (const Bureaucrat::Exception& e) {
		
        std::cout << getName() << " couldn’t sign " << form.getFormName() << " because " << e.getMessage() << std::endl;
    }
}

Bureaucrat::Exception::Exception( const std::string& msg ): _msg(msg) {
}

Bureaucrat::Exception::~Exception() {
}

	std::string Bureaucrat::Exception::getMessage() const {
	
	return this->_msg;
}

std::ostream &operator<<( std::ostream &os, const Bureaucrat &instance ) {
	
	os << instance.getName() << " bureaucrat grade " << instance.getGrade();
	
	return os;
}

