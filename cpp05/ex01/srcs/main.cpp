/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thiew <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 14:03:45 by thiew             #+#    #+#             */
/*   Updated: 2025/01/31 12:36:24 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.hpp"

int	main(void)
{
	try {
		Bureaucrat	bobi;
		Bureaucrat	boris("boris", 1);
		Bureaucrat	muhi("muhi", 47);
		Form		animaCruelty;
		Form		StealFromThePoor("StealFromThePoor", 1, 1);
		Form		CriminalStupidity("CriminalStupidity", 45, 30);
		Form		RacistUncle("RacistUncle", 150, 150);

		std::cout << "--------------------------------------\n";
		// Bureaucrat	neopren("neopren", 0);
		// Bureaucrat	marta("marta", 151);
		std::cout << bobi << boris << muhi;
		std::cout << animaCruelty << StealFromThePoor << CriminalStupidity << RacistUncle;

		std::cout << "--------------------------------------\nsigning forms\n";
		muhi.signForm(animaCruelty);
		muhi.signForm(RacistUncle);
		boris.signForm(StealFromThePoor);
		boris.signForm(StealFromThePoor);
		
		std::cout << "--------------------------------------\n";
		std::cout << animaCruelty << StealFromThePoor << CriminalStupidity << RacistUncle;
		muhi.signForm(StealFromThePoor);
	} catch (std::exception &e)
	{
		std::cout << "--------------------------------------\n";
		std::cout << "exception caught: " << e.what() << "\n";
	}

	try
	{
		Bureaucrat	boris("boris", 1);
		Bureaucrat	muhi("muhi", 47);
		Form		CriminalStupidity("CriminalStupidity", 0, 30);

		std::cout << "--------------------------------------\nincrementing tests\n";
		muhi.incrementGrade();
		std::cout << "after increment " << muhi;
		muhi.decrementGrade();
		std::cout << "after decrement " << muhi;
		muhi.signForm(CriminalStupidity);
		std::cout << "--------------------------------------\n";
	} catch (std::exception &e)
	{
		std::cout << "--------------------------------------\n";
		std::cout << "exception caught: " << e.what() << "\n";
	}
}
