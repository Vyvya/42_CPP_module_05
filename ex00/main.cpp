/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgejno <vgejno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 18:01:18 by vgejno            #+#    #+#             */
/*   Updated: 2023/08/08 22:00:01 by vgejno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {

	Bureaucrat B1("Jo", 5);
	std::cout << "Bureaucrat details: " << B1 << std::endl;
	//Copy
	Bureaucrat B2(B1);
	std::cout << "Bureaucrat details: " << B2 << std::endl;

	Bureaucrat B3("Vu", 7);
	std::cout << "Bureaucrat details: " << B3 << std::endl;

	
	B3 = B1;
	std::cout << "Bureaucrat details: " << B3 << std::endl;

	try {
		/* do some stuff with bureaucrats */
	}
	catch( std::exception & e) {
		
		/* do some stuff with bureaucrats */
	}
	
	return 0;
}