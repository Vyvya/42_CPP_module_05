/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgejno <vgejno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 18:01:18 by vgejno            #+#    #+#             */
/*   Updated: 2023/08/12 22:55:22 by vgejno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

// void tryGradeOkSign() {

// 	std::cout << GR << "	# Test tryGradeOk #	" << std::endl << std::endl;
	
// 	try {
		
// 		Bureaucrat B100("Jo", 100);
// 		std::cout << B100 << std::endl;
// 		B100.signForm()
		
// 	} catch( Bureaucrat::Exception& e ) {
				
// 		std::cout << "Bureaucrat::" << e.getMessage() << std::endl;
// 	}
	
// 	try {
		
// 		Bureaucrat B150("Max", 150);
// 		std::cout << B150 << std::endl;
		
// 	} catch( Bureaucrat::Exception& e ) {
				
// 		std::cout << "Bureaucrat::" << e.getMessage() << std::endl;
// 	}

// 	try {
		
// 		Bureaucrat B1("Min", 1);
// 		std::cout << B1 << std::endl;
		
// 	} catch( Bureaucrat::Exception& e ) {
				
// 		std::cout << "Bureaucrat::" << e.getMessage() << std::endl;
// 	}
	
// 	std::cout << RS;

// }

// void tryGradeToLow() {

// 	std::cout << BL << "	# Test tryGradeToLow #	" << std::endl << std::endl;

// 	try {
		
// 		Bureaucrat B0("Nul", 0);
// 		std::cout << B0 << std::endl;
		
// 	} catch( Bureaucrat::Exception& e ) {
				
// 		std::cout << "Bureaucrat::" << e.getMessage() << std::endl;
// 	}

// 	try {
		
// 		Bureaucrat Bmin("Minus", -8);
// 		std::cout << Bmin << std::endl;
		
// 	} catch( Bureaucrat::Exception& e ) {
				
// 		std::cout << "Bureaucrat::" << e.getMessage() << std::endl;
// 	}
	
// 	std::cout << RS;

// }

// void tryGradeToHigh() {

// 	std::cout << OR << "	# Test tryGradeToHigh #	" << std::endl << std::endl;

// 	try {
		
// 		Bureaucrat B200("Chet", 200);
// 		std::cout << B200 << std::endl;
		
// 	} catch( Bureaucrat::Exception& e ) {
				
// 		std::cout << "Bureaucrat::" << e.getMessage() << std::endl;
// 	}

// 	std::cout << RS;

// }

// void tryGradeIncrement() {

// 	std::cout << VL << "	# Test tryGradeIncrement #	" << std::endl << std::endl;
	
// 	try {
		
// 		int grade = 150;
		
// 		Bureaucrat B150("Max", grade);
// 		std::cout << B150 << std::endl;
		
// 		B150.incrementGrade();
// 		std::cout << B150 << std::endl;
		
// 	} catch( Bureaucrat::Exception& e ) {
				
// 		std::cout << "Bureaucrat::" << e.getMessage() << std::endl;
// 	}

// 	try {
		
// 		int grade = 1;
		
// 		Bureaucrat B1("Min", grade);
// 		std::cout << B1 << std::endl;

// 		B1.incrementGrade();
// 		std::cout << B1 << std::endl;
		
// 	} catch( Bureaucrat::Exception& e ) {
				
// 		std::cout << "Bureaucrat::" << e.getMessage() << std::endl;
// 	}

// 	std::cout << RS;

// }

// void tryGradeDecrement() {

// 	std::cout << GN << "	# Test tryGradeDecrement #	" << std::endl << std::endl;
	
// 	try {
		
// 		int grade = 150;
		
// 		Bureaucrat B150("Max", grade);
// 		std::cout << B150 << std::endl;
		
// 		B150.decrementGrade();
// 		std::cout << B150 << std::endl;
		
// 	} catch( Bureaucrat::Exception& e ) {
				
// 		std::cout << "Bureaucrat::" << e.getMessage() << std::endl;
// 	}

// 	try {
		
// 		int grade = 1;
		
// 		Bureaucrat B1("Min", grade);
// 		std::cout << B1 << std::endl;

// 		B1.decrementGrade();
// 		std::cout << B1 << std::endl;
		
// 	} catch( Bureaucrat::Exception& e ) {
				
// 		std::cout << "Bureaucrat::" << e.getMessage() << std::endl;
// 	}

// 	std::cout << RS;

// }

void copyBureaucratTest() {
	
	std::cout << YL << "	# Test Bureaucrat copy #	" << std::endl << std::endl;

	Bureaucrat B100("Jo", 100);
	std::cout << B100 << std::endl;

	Bureaucrat B130(B100);
	std::cout << B130 << std::endl;
	
	std::cout << std::endl;
	
	std::cout << MAG << "	# Test Bureaucrat assignement operator #	" << std::endl << std::endl;

	Bureaucrat B1("BMin", 1);
	std::cout << B1 << std::endl;

	Bureaucrat B150("BMax", 150);
	std::cout << B150 << std::endl;

	B150 = B1;
	std::cout << B150 << std::endl;

}

void copyFormTest() {
	
	std::cout << YL << "	# Test Form copy #	" << std::endl << std::endl;

	Form F100("F100", 100, 100);
	std::cout << F100 << std::endl;

	Form F130(F100);
	std::cout << F130 << std::endl;
	
	std::cout << std::endl;
	
	std::cout << MAG << "	# Test Form assignement operator #	" << std::endl << std::endl;

	Form F1("FMin", 1, 2);
	std::cout << F1 << std::endl;

	Form F150("FMax", 150, 150);
	std::cout << F150 << std::endl;

	F150 = F1;
	std::cout << F150 << std::endl;

}

void tryFormGradeOk() {

	std::cout << GR << "	# Test tryFormGradeOk #	" << std::endl << std::endl;
	
	Bureaucrat B100("Jo", 100);
	std::cout << B100 << std::endl;
	
	Form F100("F100", 100, 20);
	std::cout << F100 << std::endl;
	
	F100.beSigned( B100 );
	B100.signForm( F100 );
	std::cout << F100 << std::endl;
	
	std::cout << std::endl;

	B100.incrementGrade();
	std::cout << B100 << std::endl;

	F100.beSigned( B100 );
	B100.signForm( F100 );
	std::cout << F100 << std::endl;

	std::cout << std::endl;

	Bureaucrat B9("Bi", 9);
	std::cout << B9 << std::endl;
	
	Form F9("F9", 9, 5);
	std::cout << F9 << std::endl;
	
	// F9.beSigned( B9 );
	// B9.signForm( F9);
	// std::cout << F9 << std::endl;
	
	// std::cout << std::endl;
	
	B9.decrementGrade();
	std::cout << B9 << std::endl;

	F9.beSigned( B9 );
	B9.signForm( F9 );
	std::cout << F9 << std::endl;
}

void tryFormGradeToLow() {

	std::cout << BL << "	# Test tryFormGradeToLow #	" << std::endl << std::endl;

	try {
		
		Form F00("F00", 0, 0);
		std::cout << F00 << std::endl;
		
	} catch( Form::Exception& e ) {
				
		std::cout << "Form::" << e.getMessage() << std::endl;
	}

	try {
		
		Form F010("F010", 1, 0);
		std::cout << F010 << std::endl;
		
	} catch( Form::Exception& e ) {
				
		std::cout << "Form::" << e.getMessage() << std::endl;
	}

	try {
		
		Form F001("F001", 0, 1);
		std::cout << F001 << std::endl;
		
	} catch( Form::Exception& e ) {
				
		std::cout << "Form::" << e.getMessage() << std::endl;
	}

	try {
		
		Form F00min("F00min", -6, -1);
		std::cout << F00min << std::endl;
		
	} catch( Form::Exception& e ) {
				
		std::cout << "Form::" << e.getMessage() << std::endl;
	}
	
	std::cout << RS;

}

void tryFormGradeToHigh() {

	std::cout << OR << "	# Test tryFormGradeToHigh #	" << std::endl << std::endl;

	try {
		
		Form F200("F200", 200, 200);
		std::cout << F200 << std::endl;
		
	} catch( Form::Exception& e ) {
				
		std::cout << "Form::" << e.getMessage() << std::endl;
	}

	try {
		
		Form F3200("F3200", 3, 200);
		std::cout << F3200 << std::endl;
		
	} catch( Form::Exception& e ) {
				
		std::cout << "Form::" << e.getMessage() << std::endl;
	}

	try {
		
		Form F2003("F2003", 200, 3);
		std::cout << F2003 << std::endl;
		
	} catch( Form::Exception& e ) {
				
		std::cout << "Form::" << e.getMessage() << std::endl;
	}

	std::cout << RS;

}

// void trySignForm() {

// 	tryGradeOkSign();
// 	std::cout << std::endl;
	
// 	tryGradeToLowSign();
// 	std::cout << std::endl;
	
// 	tryGradeToHighSign();
// 	std::cout << std::endl;

// 	tryGradeIncrementSign();
// 	std::cout << std::endl;

// 	tryGradeDecrementSign();
	
// }

int main() {
	
	copyBureaucratTest();
	std::cout << std::endl;
	
	copyFormTest();
	std::cout << std::endl;
	
	tryFormGradeOk();
	std::cout << std::endl;
	
	// tryFormGradeToLow();
	// std::cout << std::endl;
	
	// tryFormGradeToHigh();
	// std::cout << std::endl;

	// trySignForm();

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
