/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 17:28:45 by tjuvan            #+#    #+#             */
/*   Updated: 2024/12/13 14:56:07 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScavTrap.hpp"

/* constructors */
ScavTrap::ScavTrap() : ClapTrap()
{  
	_name = "scavy";
	_hit_points = 100; 
	_energy_points = 50; 
	_attack_dmg = 20; 
	_guarding = false;
	std::cout << "ScavTrap\n";
}

ScavTrap::ScavTrap( const ScavTrap &copy) : ClapTrap(copy) 
{ _guarding = copy._guarding; std::cout << "ScavTrap\n"; }

ScavTrap::ScavTrap( const std::string name) : ClapTrap(name) 
{ 
	_guarding = false;
	_name = name;
	_hit_points = 100; 
	_energy_points = 50; 
	_attack_dmg = 20; 
	std::cout << "ScavTrap\n";
}

ScavTrap::~ScavTrap() { std::cout << "Scavtrap dead\n"; }

/* overload */
ScavTrap 	&ScavTrap::operator=(const ScavTrap &other)
{
	std::cout << "ScavTrap assignment" << std::endl;
	_name = other._name;
	_hit_points = other._hit_points;
	_energy_points = other._energy_points;
	_attack_dmg = other._attack_dmg;
	_guarding = other._guarding;
	return *this;
}

/* Getter/setter */
bool	ScavTrap::getGate() const { return (_guarding); }
void	ScavTrap::setGate(const bool &value) { _guarding = value; }	

/* methods */
void	ScavTrap::GuardGate() 
{
	if (_hit_points < 1)
	{
		std::cout << _name << " obivously cant guard the gate right now, since he is DEAD!\n";
		return;
	}
	if (_guarding == true)
	{
		std::cout << _name << " is already guarding the gate\n";
		return ;
	}
	_guarding = !_guarding;
	std::cout << _name << " started guarding the gate\n";
}
