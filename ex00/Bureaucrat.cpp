/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgejno <vgejno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 18:01:58 by vgejno            #+#    #+#             */
/*   Updated: 2023/08/08 21:59:24 by vgejno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {
	
	std::cout << "Bureaucrat came to office" << std::endl;
}

Bureaucrat::~Bureaucrat() {
	
	std::cout << "Bureaucrat " << this->_name << " went home" << std::endl;
}

Bureaucrat::Bureaucrat( const std::string name, int grade ) : _name(name), _grade(grade) {
	
	std::cout << "Bureaucrat " << this->_name << " graded " << this->_grade << " is in office" << std::endl;
}

//For a const member variable like _name, it must be initialized in the member 
//initialization list since it cannot be assigned to after construction. 
//Direct assignments inside the constructor body are not allowed for 
//const members., the correct way to initialize _name in the copy constructor 
//is through the member initialization list
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

const std::string Bureaucrat::getName() const{

	return this->_name;
}

int Bureaucrat::getGrade() const {

	return this->_grade;
}

std::ostream &operator<<( std::ostream &os, const Bureaucrat &instance ) {
	
	os << instance.getName() << " graded " << instance.getGrade();
	
	return os;
}