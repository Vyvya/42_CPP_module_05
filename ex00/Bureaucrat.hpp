/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgejno <vgejno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 18:01:45 by vgejno            #+#    #+#             */
/*   Updated: 2023/08/08 21:54:22 by vgejno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>

class Bureaucrat {

	private:

		const std::string _name;
		int _grade;
		
	public:
		
		Bureaucrat();
		Bureaucrat( const std::string name, int grade);
		Bureaucrat( const Bureaucrat& other );
		~Bureaucrat();

		Bureaucrat& operator=( const Bureaucrat& other );
		const std::string getName() const;
		int getGrade() const;

};

std::ostream &operator<<( std::ostream &os, const Bureaucrat &instance );

#endif