/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgejno <vgejno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 18:01:18 by vgejno            #+#    #+#             */
/*   Updated: 2023/08/11 14:50:07 by vgejno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

void tryGradeOk() {

	std::cout << GR << "	# Test tryGradeOk #	" << std::endl << std::endl;
	
	try {
		
		Bureaucrat B100("Jo", 100);
		std::cout << B100 << std::endl;
		
	} catch( Bureaucrat::Exception& e ) {
				
		std::cout << "Bureaucrat::" << e.getMessage() << std::endl;
	}
	
	try {
		
		Bureaucrat B150("Max", 150);
		std::cout << B150 << std::endl;
		
	} catch( Bureaucrat::Exception& e ) {
				
		std::cout << "Bureaucrat::" << e.getMessage() << std::endl;
	}

	try {
		
		Bureaucrat B1("Min", 1);
		std::cout << B1 << std::endl;
		
	} catch( Bureaucrat::Exception& e ) {
				
		std::cout << "Bureaucrat::" << e.getMessage() << std::endl;
	}
	
	std::cout << RS;

}

void tryGradeToLow() {

	std::cout << BL << "	# Test tryGradeToLow #	" << std::endl << std::endl;

	try {
		
		Bureaucrat B0("Nul", 0);
		std::cout << B0 << std::endl;
		
	} catch( Bureaucrat::Exception& e ) {
				
		std::cout << "Bureaucrat::" << e.getMessage() << std::endl;
	}
	
	std::cout << RS;

}

void tryGradeToHigh() {

	std::cout << OR << "	# Test tryGradeToHigh #	" << std::endl << std::endl;

	try {
		
		Bureaucrat B200("Chet", 200);
		std::cout << B200 << std::endl;
		
	} catch( Bureaucrat::Exception& e ) {
				
		std::cout << "Bureaucrat::" << e.getMessage() << std::endl;
	}

	std::cout << RS;

}

void tryGradeIncrement() {

	std::cout << VL << "	# Test tryGradeIncrement #	" << std::endl << std::endl;
	
	try {
		
		int grade = 150;
		
		Bureaucrat B150("Max", grade);
		std::cout << B150 << std::endl;
		
		B150.incrementGrade();
		std::cout << B150 << std::endl;
		
	} catch( Bureaucrat::Exception& e ) {
				
		std::cout << "Bureaucrat::" << e.getMessage() << std::endl;
	}

	try {
		
		int grade = 1;
		
		Bureaucrat B1("Min", grade);
		std::cout << B1 << std::endl;

		B1.incrementGrade();
		std::cout << B1 << std::endl;
		
	} catch( Bureaucrat::Exception& e ) {
				
		std::cout << "Bureaucrat::" << e.getMessage() << std::endl;
	}

	std::cout << RS;

}

void tryGradeDecrement() {

	std::cout << GN << "	# Test tryGradeDecrement #	" << std::endl << std::endl;
	
	try {
		
		int grade = 150;
		
		Bureaucrat B150("Max", grade);
		std::cout << B150 << std::endl;
		
		B150.decrementGrade();
		std::cout << B150 << std::endl;
		
	} catch( Bureaucrat::Exception& e ) {
				
		std::cout << "Bureaucrat::" << e.getMessage() << std::endl;
	}

	try {
		
		int grade = 1;
		
		Bureaucrat B1("Min", grade);
		std::cout << B1 << std::endl;

		B1.decrementGrade();
		std::cout << B1 << std::endl;
		
	} catch( Bureaucrat::Exception& e ) {
				
		std::cout << "Bureaucrat::" << e.getMessage() << std::endl;
	}

	std::cout << RS;

}

void copyTest() {
	
	std::cout << YL << "	# Test copy #	" << std::endl << std::endl;

	Bureaucrat B100("Jo", 100);
	std::cout << B100 << std::endl;

	Bureaucrat B130(B100);
	std::cout << B130 << std::endl;
	
	std::cout << std::endl;
	
	std::cout << MAG << "	# Test assignement operator #	" << std::endl << std::endl;

	Bureaucrat B1("Min", 1);
	std::cout << B1 << std::endl;

	Bureaucrat B150("Max", 150);
	std::cout << B150 << std::endl;

	B150 = B1;
	std::cout << B150 << std::endl;

}

int main() {
	
	copyTest();
	std::cout << std::endl;
	
	tryGradeOk();
	std::cout << std::endl;
	
	tryGradeToLow();
	std::cout << std::endl;
	
	tryGradeToHigh();
	std::cout << std::endl;

	tryGradeIncrement();
	std::cout << std::endl;

	tryGradeDecrement();

	return 0;
}

// int main() {

// 	try {
		
// 		const int numBueraucrats = 8;
		
// 		Bureaucrat b[numBueraucrats] = {
			
// 			Bureaucrat("Jo", 100),
// 			Bureaucrat("Nul", 0),
// 			Bureaucrat("Bob", -9),
// 			Bureaucrat("Chet", 200),
// 			Bureaucrat("Decre", 148),
// 			Bureaucrat("Incre", 5),
// 			Bureaucrat("TooDecre", 150),
// 			Bureaucrat("TooIncre", 1)

// 		};

// 		for( int i = 0; i < numBueraucrats; ++i) {
			
// 			try {
				
// 				std::cout << b[i] << std::endl;
				
// 			} catch( Bureaucrat::Exception& e ) {
				
// 				std::cout << "Bureaucrat::" << e.getMessage() << std::endl;
// 			}
// 		}
			
// 	}	catch( Bureaucrat::Exception& e ) {
		
// 			std::cout << "Bureaucrat::" << e.getMessage() << std::endl;
// 	}
// }
