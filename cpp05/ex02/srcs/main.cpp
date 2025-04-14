/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thiew <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 14:03:45 by thiew             #+#    #+#             */
/*   Updated: 2025/01/04 14:07:50 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.hpp"

int	main(void)
{
	try {
		Bureaucrat	bobi;
		Bureaucrat	boris("boris", 1);
		Bureaucrat	muhi("muhi", 47);
		ShrubberyCreationForm forest("forest");
		RobotomyRequestForm	robot("50 cent");
		PresidentialPardonForm rubberBandit("Rubber Bandit");

		std::cout << "--------------------------------------\n";
		// Bureaucrat	neopren("neopren", 0);
		// Bureaucrat	marta("marta", 151);
		std::cout << bobi << boris << muhi;

		std::cout << "--------------------------------------\nsigning forms\n";
		muhi.signForm(forest);
		muhi.signForm(robot);
		boris.signForm(rubberBandit);

		
		std::cout << "--------------------------------------executing forms\n";
		muhi.executeForm(forest);
		muhi.incrementGrade();
		muhi.incrementGrade();
		muhi.executeForm(robot);
		boris.executeForm(rubberBandit);
		while (boris.getGrade() <= 6)
			boris.decrementGrade();
		boris.executeForm(rubberBandit);
		std::cout << "--------------------------------------\nincrementing tests\n";
		muhi.incrementGrade();
		std::cout << "after increment " << muhi;
		muhi.decrementGrade();
		std::cout << "after decrement " << muhi;

		std::cout << "--------------------------------------\n";

		std::cout << "--------------------------------------\n";
	}

	catch (std::exception &e)
	{
		std::cout << "--------------------------------------\n";
		std::cout << "exception caught: " << e.what() << "\n";
	}


}
