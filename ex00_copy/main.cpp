/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgejno <vgejno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 18:01:18 by vgejno            #+#    #+#             */
/*   Updated: 2023/08/10 18:57:35 by vgejno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

	#include "Bureaucrat.hpp"

	void gradeToHigh() {

	throw(Bureaucrat::Exception("GradeTooHighException"));
	}

	void gradeToLow() {

	throw(Bureaucrat::Exception("GradeTooLowException"));
	}

	int main() {

	try {
		
		Bureaucrat B1("Jo", 100);
		Bureaucrat B0("Nul", 0);
		Bureaucrat B2("Bob", -9);
		Bureaucrat B3("Chet", 200);

		std::cout << B1 << std::endl;
		
		if ( B1.getGrade() < 1 )
			gradeToLow();
		
		if ( B1.getGrade() > 150 )
			gradeToHigh();
			
	}

	catch(Bureaucrat::Exception& e) {
		
		std::cout << "Bureaucrat::" << e.getMessage() << std::endl;
	}
	}

void office() {
	
	
}

// int main() {

// 	// Bureaucrat B1("Jo", 5);
// 	// std::cout << "Bureaucrat details: " << B1 << std::endl;
// 	// //Copy
// 	// Bureaucrat B2(B1);
// 	// std::cout << "Bureaucrat details: " << B2 << std::endl;

// 	// Bureaucrat B3("Vu", 7);
// 	// std::cout << "Bureaucrat details: " << B3 << std::endl;

	
// 	// B3 = B1;
// 	// std::cout << "Bureaucrat details: " << B3 << std::endl;

// 	try {
		
// 		Bureaucrat B1("Jo", 500);
// 		std::cout << "Bureaucrat details: " << B1 << std::endl;
// 		//Copy
// 		// Bureaucrat B2(B1);
// 		// std::cout << "Bureaucrat details: " << B2 << std::endl;

// 		// Bureaucrat B3("Vu", 7);
// 		// std::cout << "Bureaucrat details: " << B3 << std::endl;

		
// 		// B3 = B1;
// 		// std::cout << "Bureaucrat details: " << B3 << std::endl;
		
		
// 		if ( B1.getGrade() < 1 ) {
			
// 			throw ("GradeTooLowException");
// 		}
// 		if ( B1.getGrade() > 150 ) {
			
// 			throw ("GradeTooHighException");
// 		}
// 	}
// 	catch( std::exception & e) {
		
// 		/* do some stuff with bureaucrats */
// 		std::cout << "Bureaucrat::" << e.what() << std::endl;
// 	}
	
// 	return 0;
// }
