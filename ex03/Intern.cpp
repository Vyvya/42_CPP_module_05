/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgejno <vgejno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 21:53:31 by vgejno            #+#    #+#             */
/*   Updated: 2023/08/15 17:06:09 by vgejno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/Intern.hpp"
#include "headers/AForm.hpp"
#include "headers/Bureaucrat.hpp"
#include "headers/ShrubberyCreationForm.hpp"
#include "headers/RobotomyRequestForm.hpp"
#include "headers/PresidentialPardonForm.hpp"

Intern::Intern() {

	std::cout << "Intern constructor called" << std::endl;
}

Intern::~Intern() {

	std::cout << "Intern deconstructor called" << std::endl;
}

Intern::Intern( const Intern& other) {

	(void)other;
	
	// std::cout << "Intern copy constructor called" << std::endl;
}

Intern &Intern::operator=( const Intern& other ) {

	// std::cout << "Intern copy assignement operator called" << std::endl;

	if( this != &other) {

		return *this;
	}
	return *this;
}

AForm* createShrubbery( std::string target ) {

	return (new ShrubberyCreationForm(target));
}

AForm* createRobotomy( std::string target ) {

	return (new RobotomyRequestForm(target));
}

AForm* createPresidential( std::string target ) {

	return (new PresidentialPardonForm(target));
}

AForm* Intern::makeForm(const std::string nameForm, const std::string target) {
	
    std::string forms[3] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
	
    AForm* (*createForm[3])(const std::string) = {&createShrubbery, &createRobotomy, &createPresidential};
	
    for (int i = 0; i < 3; i++) {
        if (nameForm == forms[i]) {

            return createForm[i](target);
        }
    }
	
    std::cout << "Error: Intern cannot create form " << nameForm << std::endl;
    return nullptr;
}
