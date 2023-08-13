/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgejno <vgejno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 18:01:18 by vgejno            #+#    #+#             */
/*   Updated: 2023/08/13 18:12:39 by vgejno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

void tryGradeIncrement() {

	std::cout << VL << "	# Test tryGradeIncrement #	" << std::endl << std::endl;
	
	Bureaucrat B100("Jo", 100);
	std::cout << B100 << std::endl;
	
	Form F100("F100", 100, 20);
	std::cout << F100 << std::endl;
	
	B100.incrementGrade();
	std::cout << B100 << std::endl;

	F100.beSigned( B100 );
	B100.signForm( F100 );
	std::cout << F100 << std::endl;

	std::cout << RS;
	std::cout << std::endl;

}

void tryGradeDecrement() {

	std::cout << GN << "	# Test tryGradeDecrement #	" << std::endl << std::endl;
	
	Bureaucrat B9("Bi", 9);
	std::cout << B9 << std::endl;
	
	Form F9("F9", 9, 5);
	std::cout << F9 << std::endl;
	
	B9.decrementGrade();
	std::cout << B9 << std::endl;

	F9.beSigned( B9 );
	B9.signForm( F9 );
	std::cout << F9 << std::endl;

	std::cout << RS;
	std::cout << std::endl;

}

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

	std::cout << RS;
	std::cout << std::endl;

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

	std::cout << RS;
	std::cout << std::endl;

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

	Bureaucrat B30("Jo", 30);
	std::cout << B30 << std::endl;
	
	Form F16("F16", 16, 20);
	std::cout << F16 << std::endl;
	
	F16.beSigned( B30 );
	B30.signForm( F16 );
	std::cout << F16 << std::endl;
	
	std::cout << RS;
	std::cout << std::endl;
}

void tryFormGradeToLow() {

	std::cout << BL << "	# Test tryFormGradeToLow #	" << std::endl << std::endl;

	Form F00("F00", 0, 0);
	std::cout << F00 << std::endl;
	
	Bureaucrat B100("Jo", 100);
	std::cout << B100 << std::endl;
	
	F00.beSigned( B100 );
	B100.signForm( F00 );
	std::cout << F00 << std::endl;
	
	std::cout << std::endl;

	Form F010("F010", 1, 0);
	std::cout << F010 << std::endl;
		
	Bureaucrat B1("One", 1);
	std::cout << B1 << std::endl;
	
	F010.beSigned( B1 );
	B1.signForm( F010 );
	std::cout << F010 << std::endl;
	
	std::cout << RS;
	std::cout << std::endl;
}

void tryFormGradeToHigh() {

	std::cout << OR << "	# Test tryFormGradeToHigh #	" << std::endl << std::endl;

	Form F151("F151", 151, 1);
	std::cout << F151 << std::endl;
	
	Bureaucrat B100("Jo", 100);
	std::cout << B100 << std::endl;
	
	F151.beSigned( B100 );
	B100.signForm( F151 );
	std::cout << F151 << std::endl;

	std::cout << RS;
	std::cout << std::endl;
}

int main() {
	
	copyBureaucratTest();
	std::cout << std::endl;
	
	copyFormTest();
	std::cout << std::endl;
	
	tryFormGradeOk();
	std::cout << std::endl;
	
	tryFormGradeToLow();
	std::cout << std::endl;
	
	tryFormGradeToHigh();
	std::cout << std::endl;

	tryGradeIncrement();
	std::cout << std::endl;

	tryGradeDecrement();
	std::cout << std::endl;

	return 0;
}
