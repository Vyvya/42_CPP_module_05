/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgejno <vgejno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 18:01:58 by vgejno            #+#    #+#             */
/*   Updated: 2023/08/10 19:01:33 by vgejno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {
	
	std::cout << "Bureaucrat came to office" << std::endl;
}

Bureaucrat::~Bureaucrat() {
	
	std::cout << "Bureaucrat " << this->_name << " went home" << std::endl;
}

Bureaucrat::Bureaucrat( const std::string name, int grade ) : _name(name) {
	
	
	if( grade < 1 )
		throw Exception ("GradeTooLowException");
		
	if( grade > 150 )
		throw Exception ("GradeTooHighException");

	_grade = grade;
	
	std::cout << "Bureaucrat " << this->_name << " grade " << this->_grade << " came to office" << std::endl;
}


//For a const member variable like _name, it must be initialized in the member 
//initialization list since it cannot be assigned to after construction. 
//Direct assignments inside the constructor body are not allowed for 
//const members., the correct way to initialize _name in the copy constructor 
//is through the member initialization list
Bureaucrat::Bureaucrat( const Bureaucrat& other ) : _name( other._name ) {

	this->_grade = other._grade;
	// std::cout << "Copy constructor on Bureaucrat " << other << " called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=( const Bureaucrat& other ) {

	if( this != &other ) {
		
		this->_grade = other._grade;
	}
	
	// std::cout << "Copy assignement operator on Bureaucrat " << other << " called" << std::endl;
	return *this;
}

const std::string Bureaucrat::getName() const{

	return this->_name;
}

int Bureaucrat::getGrade() const {

	// if( this->_grade < 1 || this->_grade > 150 ) {
		
	// 	if( this->_grade < 1 )
	// 		std::cout << "Bureaucrat::GradeTooLowException " << this->_name << " bureaucrat grade " << this->_grade << std::endl;
	// 	if( this->_grade > 150 )
	// 		std::cout  << "Bureaucrat::GradeTooHighException " << this->_name << " bureaucrat grade " << this->_grade << std::endl;	
	// }
	
	return this->_grade;
}

void Bureaucrat::setGrade( const int grade ) {

	this->_grade = grade;
}


int Bureaucrat::incrementGrade() {

	return _grade--;
}

int Bureaucrat::decrementGrade() {

	return _grade++;
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