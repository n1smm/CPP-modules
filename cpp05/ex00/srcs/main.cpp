/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thiew <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 14:03:45 by thiew             #+#    #+#             */
/*   Updated: 2025/01/31 12:37:39 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.hpp"

int	main(void)
{
	try {
		Bureaucrat	bobi;
		Bureaucrat	boris("boris", 1);
		Bureaucrat	muhi("muhi", 47);
		std::cout << "--------------------------------------\n";
		// Bureaucrat	neopren("neopren", 0);
		// Bureaucrat	marta("marta", 151);
		std::cout << bobi << boris << muhi;
		std::cout << "--------------------------------------\nincrementing tests\n";
		muhi.incrementGrade();
		std::cout << "after increment " << muhi;
		muhi.decrementGrade();
		std::cout << "after decrement " << muhi;
		std::cout << "--------------------------------------\n";
		boris.incrementGrade();
		std::cout << "after increment " << boris; // should throw exception
		std::cout << "--------------------------------------\n";
	}

	catch (std::exception &e)
	{
		std::cout << "--------------------------------------\n";
		std::cout << "exception caught: " << e.what() << "\n";
	}
	try {
		Bureaucrat	Elon("Elon", 160);
	} catch (Bureaucrat::GradeTooLowException &e)
	{ std::cout << "exception caught: " << e.what() << "\n"; }

}
