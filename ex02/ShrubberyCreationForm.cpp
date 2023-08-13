/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgejno <vgejno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 18:27:00 by vgejno            #+#    #+#             */
/*   Updated: 2023/08/13 21:56:28 by vgejno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

// ShrubberyCreationForm::ShrubberyCreationForm() {
	
// 	std::cout << "ShrubberyCreationForm constructor called" << std::endl;
// }

ShrubberyCreationForm::ShrubberyCreationForm( std::string target ) : AForm(target, 145, 137) {
	
	std::cout << "ShrubberyCreationForm constructor signGrade" << this->getAFormSignGrade() \
	<< " executeGrade " << this->getAFormExecuteGrade() << " called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	
	std::cout << "ShrubberyCreationForm deconstructor signGrade" << this->getAFormSignGrade() \
	<< " executeGrade " << this->getAFormExecuteGrade() << " called" << std::endl;
}

bool ShrubberyCreationForm::execute(Bureaucrat const & executor) {
	
	std::cout << executor.getGrade() << std::endl;
	std::cout << this->getAFormSignGrade() << std::endl;
	std::cout << this->_checkAFormSigned() << std::endl;


	
	try {

		if( (executor.getGrade() <= this->getAFormExecuteGrade())) { // && this->_checkAFormSigned() == true 

			this->_formTree();
			return true;
			
		} else {
			
			throw ExceptionFile ("File corrupted");
		}
		
	} catch (const ExceptionFile& e) {

		std::cout << "ShrubberyCreationForm::" << e.getMessage() << std::endl;
	}
	
	return false;
}

void ShrubberyCreationForm::_formTree(void) {

	std::string filename = getAFormName() + "_shrubbery";
	std::ofstream outputFile(filename);

	if( outputFile.is_open() ) {
		
		outputFile << "                  ,@,\n";
		outputFile << "                 ,@@@,\n";
		outputFile << "               ,@@@@@@@,\n";
		outputFile << "       ,,,.   ,@@@@@@/@@,  .o88888o.\n";
		outputFile << "    ,&%&&%&&%,@@@@@/@@@@@@,8888888/8o\n";
		outputFile << "   ,%&&&&&%&&%,@@@@@@@/@@@88888888/88'\n";
		outputFile << "   %&&%&%&/%&&%@@@@@/ /@@@88888888888'\n";
		outputFile << "   %&&%/ %&&&&&@@@ V /@@' `8888 `/88'\n";
		outputFile << "   `&%> ` <%&'    |.|       '8| |8'\n";
		outputFile << "       |o|        | |         | |\n";
		outputFile << "       |.|        | |         | |\n";
		outputFile << "_______| |_/__/  ,| |__ /.  __| |__/_\n";

		

		outputFile.close();
		std::cout << "ASCII trees written to " << filename << std::endl;
		
	} else {
		
        std::cerr << "Failed to open file for writing." << std::endl;
    }
}

ShrubberyCreationForm::ExceptionFile::ExceptionFile( const std::string& msg ) : _msg(msg) {
}

ShrubberyCreationForm::ExceptionFile::~ExceptionFile() {
}

	std::string ShrubberyCreationForm::ExceptionFile::getMessage() const {
	
	return this->_msg;
}
