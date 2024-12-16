/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 17:28:45 by tjuvan            #+#    #+#             */
/*   Updated: 2024/12/13 15:13:27 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/DiamondTrap.hpp"

/* constructors */
DiamondTrap::DiamondTrap() : ClapTrap("DimondyDT_clap_name")
{  
	_name = "Diamondy";
	_hit_points = FragTrap::_hit_points; 
	_energy_points = ScavTrap::_energy_points; 
	_attack_dmg = FragTrap::_attack_dmg; 
	std::cout << "DiamondTrap\n";
}

DiamondTrap::DiamondTrap( const DiamondTrap &copy) : ClapTrap(copy) {}

DiamondTrap::DiamondTrap( const std::string name) : ClapTrap(name + "_clap_name")
{ 
	this->_name = name;
	this->_hit_points = FragTrap::_hit_points; 
	this->_energy_points = ScavTrap::_energy_points; 
	this->_attack_dmg = FragTrap::_attack_dmg; 
	std::cout << "DiamondTrap\n";
}

DiamondTrap::~DiamondTrap() { std::cout << "DiamondTrap dead\n"; }

/* methods */
void	DiamondTrap::whoAmI() { std::cout << "My name: " << this->_name << ", my claptrap name: " << ClapTrap::_name << std::endl; }
