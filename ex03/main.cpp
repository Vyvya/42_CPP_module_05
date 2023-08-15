/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgejno <vgejno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 18:01:18 by vgejno            #+#    #+#             */
/*   Updated: 2023/08/15 17:21:01 by vgejno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/Bureaucrat.hpp"
#include "headers/AForm.hpp"
#include "headers/ShrubberyCreationForm.hpp"
#include "headers/RobotomyRequestForm.hpp"
#include "headers/PresidentialPardonForm.hpp"
#include "headers/Intern.hpp"

void tryPresidentialPardonForm() {

	std::cout << GR << "	# Test tryPresidentialPardonForm #	" << std::endl << std::endl;
	
	Intern I1;
	AForm *F3 = I1.makeForm("PresidentialPardonForm", "Free");

	std::cout << *F3 << std::endl;

	Bureaucrat B2("Jud", 2);
	std::cout << B2 << std::endl;

	(*F3).execute(B2);
	std::cout << std::endl;
	
	(*F3).beSigned(B2);
	B2.signAForm(*F3);
	// F3.execute(B2);
	B2.executeForm(*F3);

	std::cout << std::endl;

	Intern I2;
	AForm *F5 = I2.makeForm("PresidentialPardonForm", "Freedom");
	std::cout << *F5 << std::endl;

	Bureaucrat B150("Jud", 150);
	std::cout << B150 << std::endl;

	(*F5).execute(B150);
	std::cout << std::endl;
	
	(*F5).beSigned(B150);
	B150.signAForm(*F5);
	// F5.execute(B150);
	B150.executeForm(*F5);
	
	std::cout << RS;
	std::cout << std::endl;
	
	delete F3;
	delete F5;
	
	std::cout << std::endl;
}

void tryRobotomyRequestForm() {

	std::cout << BL << "	# Test tryRobotomyRequestForm #	" << std::endl << std::endl;

	Intern I1;
	AForm *F2 = I1.makeForm("RobotomyRequestForm", "Drill");

	std::cout << *F2 << std::endl;

	Bureaucrat B12("Dew", 92);
	std::cout << B12 << std::endl;

	(*F2).execute(B12);
	std::cout << std::endl;
	
	(*F2).beSigned(B12);
	B12.signAForm(*F2);
	B12.executeForm(*F2);

	std::cout << std::endl;

	Intern I2;
	AForm *F20 = I2.makeForm("RobotomyRequestForm", "Drillmore");
	
	std::cout << *F20 << std::endl;

	Bureaucrat B45("Dew", 45);
	std::cout << B45 << std::endl;

	(*F20).execute(B45);
	std::cout << std::endl;
	
	(*F20).beSigned(B45);
	B45.signAForm(*F20);
	B45.executeForm(*F20);

	std::cout << RS;
	std::cout << std::endl;
	
	delete F2;
	delete F20;
	
	std::cout << std::endl;
}

void tryShrubberyCreationForm() {

	std::cout << OR << "	# Test tryShrubberyCreationForm #	" << std::endl << std::endl;

	Intern I1;
	AForm *F1 = I1.makeForm("ShrubberyCreationForm", "Tree");
	
	std::cout << *F1 << std::endl;
	Bureaucrat B137("Jo", 137);
	std::cout << B137 << std::endl;
	
	(*F1).execute(B137);
	std::cout << std::endl;
	
	(*F1).beSigned(B137);
	B137.signAForm(*F1);
	// F1.execute(B137);
	B137.executeForm(*F1);

	std::cout << std::endl;
	
	Intern I2;
	AForm *F137 = I2.makeForm("ShrubberyCreationForm", "OneMoreTree");
	std::cout << *F137 << std::endl;

	Bureaucrat B138("Huy", 138);
	std::cout << B138 << std::endl;
	
	(*F137).execute(B138);
	std::cout << std::endl;

	// F137.beSigned(B138);
	B138.signAForm(*F137);
	// F137.execute(B138);
	B138.executeForm(*F137);
	
	std::cout << RS;
	std::cout << std::endl;
	
	delete F1;
	delete F137;
	std::cout << std::endl;
}

void tryIntern() {

	std::cout << YL << "	# Test tryIntern #	" << std::endl << std::endl;

	Intern Bla;
	AForm *F1 = Bla.makeForm("RobotomyRequestForm", "Drill");

	std::cout << std::endl;

	Intern Coucou;
	AForm *F2 = Bla.makeForm("RbotomyRequestForm", "Drill");
	
	std::cout << RS;
	std::cout << std::endl;
	
	delete F1;
	delete F2;
	
	std::cout << std::endl;
}

int main() {
	
	tryIntern();
	std::cout << std::endl;
	
	tryShrubberyCreationForm();
	std::cout << std::endl;

	tryRobotomyRequestForm();
	std::cout << std::endl;

	tryPresidentialPardonForm();

	return 0;
}
