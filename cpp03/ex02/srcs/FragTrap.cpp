/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 17:28:45 by tjuvan            #+#    #+#             */
/*   Updated: 2024/12/08 19:57:29 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FragTrap.hpp"

/* constructors */
FragTrap::FragTrap() : ClapTrap()
{  
	_name = "scavy";
	_hit_points = 100; 
	_energy_points = 100; 
	_attack_dmg = 30; 
	std::cout << "FragTrap\n";
}

FragTrap::FragTrap( const FragTrap &copy) : ClapTrap(copy) {}

FragTrap::FragTrap( const std::string name) : ClapTrap(name) 
{ 
	_name = name;
	_hit_points = 100; 
	_energy_points = 100; 
	_attack_dmg = 30; 
	std::cout << "FragTrap\n";
}

FragTrap::~FragTrap() { std::cout << "FragTrap dead\n"; }

/* Getter/setter */

/* methods */
void	FragTrap::HighFivesGuys() 
{ 
	if (_hit_points < 1)
	{
		std::cout << _name << " is dying and asking for help, you give him a highFive!\n";
		return ;
	}
	std::cout << _name << "is requesting YOU for a highFive, don't be a dick\n";
}
