/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 15:19:05 by tjuvan            #+#    #+#             */
/*   Updated: 2024/12/08 19:59:19 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.hpp"

int	main( void )
{
	ClapTrap	Miranda("Miranda");
	ScavTrap	Dziuly("Dziuly");
	ClapTrap	Lapis("Lapis");
	ScavTrap	Felix("Felix");
	FragTrap	Cestino("Cestino");

	Miranda.attack("dziuly");
	Dziuly.takeDamage(Miranda.getAttackDmg());
	Lapis.takeDamage(10);
	Lapis.attack("Felix");
	Cestino.attack("Felix");
	Cestino.HighFivesGuys();
	Lapis.beRepaired(2);
	Lapis.attack("Felix");
	Felix.takeDamage(1);
	Felix.attack("Miranda");
	Miranda.takeDamage(200);
	Miranda.beRepaired(50);
	Miranda.attack("Felix");
	Cestino.takeDamage(10000);
	Cestino.HighFivesGuys();
	Dziuly.GuardGate();
	Dziuly.GuardGate();

	std::cout << std::setw(30) << std::setfill('*') << "" << std::endl;
	std::cout << Miranda << Dziuly << Lapis << Felix << Cestino;
}
