/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 15:19:05 by tjuvan            #+#    #+#             */
/*   Updated: 2024/12/08 18:38:15 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.hpp"

int	main( void )
{
	ClapTrap	Miranda("Miranda");
	ScavTrap	Dziuly("Dziuly");
	ClapTrap	Lapis("Lapis");
	ScavTrap	Felix("Felix");

	Miranda.attack("dziuly");
	Dziuly.takeDamage(Miranda.getAttackDmg());
	Lapis.takeDamage(10);
	Lapis.attack("Felix");
	Lapis.beRepaired(2);
	Lapis.attack("Felix");
	Felix.takeDamage(1);
	Felix.attack("Miranda");
	Miranda.takeDamage(200);
	Miranda.beRepaired(50);
	Miranda.attack("Felix");
	Dziuly.GuardGate();
	Dziuly.GuardGate();

	std::cout << std::setw(30) << std::setfill('*') << "" << std::endl;
	std::cout << Miranda << Dziuly << Lapis << Felix;




}
