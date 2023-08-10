/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgejno <vgejno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 18:01:18 by vgejno            #+#    #+#             */
/*   Updated: 2023/08/10 19:21:35 by vgejno           ###   ########.fr       */
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
		
		const int numBueraucrats = 8;
		
		Bureaucrat b[numBueraucrats] = {
			
			Bureaucrat("Jo", 100),
			Bureaucrat("Nul", 0),
			Bureaucrat("Bob", -9),
			Bureaucrat("Chet", 200),
			Bureaucrat("Decre", 148),
			Bureaucrat("Incre", 5),
			Bureaucrat("TooDecre", 150),
			Bureaucrat("TooIncre", 1)

		};

		for( int i = 0; i < numBueraucrats; ++i) {
			
			try {
				
				std::cout << b[i] << std::endl;
				
			} catch( Bureaucrat::Exception& e ) {
				
				std::cout << "Bureaucrat::" << e.getMessage() << std::endl;
			}
		}
			
	}	catch( Bureaucrat::Exception& e ) {
		
			std::cout << "Bureaucrat::" << e.getMessage() << std::endl;
	}
}
