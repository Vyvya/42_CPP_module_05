/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgejno <vgejno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 18:01:58 by vgejno            #+#    #+#             */
/*   Updated: 2023/08/13 21:10:42 by vgejno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
// #include "RobotomyRequestForm.hpp"
// #include "PresidentialPardonForm.hpp"

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

void Bureaucrat::signAForm( AForm& aform ) {

	try {
		
		if ( aform._checkAFormSigned() == true ) {
			
    		std::cout << getName() << " signed " << aform.getAFormName() << std::endl; 
			
		} else {
			
			if( this->getGrade() < 1 || this->getGrade() > 150 )  {

				throw Exception ("bureaucrat has wrong permissions");
				
			} else if( (aform.getAFormExecuteGrade() < 1 || aform.getAFormExecuteGrade() > 150) \
				|| (aform.getAFormSignGrade() < 1 || aform.getAFormSignGrade() > 150) ) {

				throw Exception ("form is falsely configured");
			}
			else
				throw Exception ("bureaucrat has wrong permissions");
		}
        
    } catch (const Bureaucrat::Exception& e) {
		
        std::cout << getName() << " couldn’t sign " << aform.getAFormName() << " because " << e.getMessage() << std::endl;
    }
}

// void Bureaucrat::executeForm(AForm const & aform) {

// 	try {

// 		if( aform.getAFormExecuteGrade() >= 1 && aform.getAFormExecuteGrade() <= 150 )
// 	}
// }

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

