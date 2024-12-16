/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 14:16:57 by tjuvan            #+#    #+#             */
/*   Updated: 2024/12/13 14:00:33 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"

/* constructors */
ClapTrap::ClapTrap() : _name("clapy"), _hit_points(10), _energy_points(10), _attack_dmg(0) { }
ClapTrap::ClapTrap( std::string name ) : _name(name), _hit_points(10), _energy_points(10), _attack_dmg(0) { }
ClapTrap::~ClapTrap() { }

/* methods */
void	ClapTrap::attack( const std::string &target)
{
	if (_energy_points < 1 || _hit_points < 1)
	{ 
		std::cout << _name << " has insufficient energy or hit points for this action" << std::endl;
		return ;
	}

	std::cout << this->_name << " attacks " << target << ", causing " << this->_attack_dmg << " points of damage!" << std::endl;
	_energy_points--;
}

void	ClapTrap::takeDamage( unsigned int amount)
{
	std::cout << _name << " takes " << amount << " damage!" << std::endl;
	_hit_points -= amount;
	std::cout << _name << " has now " << _hit_points << " hit points!" << std::endl;
}

void	ClapTrap::beRepaired( unsigned int amount)
{
	if (_energy_points < 1)
	{
		std::cout << _name << " has insufficient energy points for this action" << std::endl;
		return ;
	}

	std::cout << _name << " has repaired him/herself for " << amount << std::endl;
	_hit_points += amount;
	_energy_points--;
	std::cout << " he/she now has " << _hit_points << " hit points and " << _energy_points << " energy points!" << std::endl;
}

/* getters */
std::string	ClapTrap::getName() const { return (_name); }
int			ClapTrap::getHitPoints() const { return (_hit_points); }
int			ClapTrap::getEnergyPoints() const { return (_energy_points); }
int			ClapTrap::getAttackDmg() const { return (_attack_dmg); }
/* setters */
void		ClapTrap::setName(const std::string &name) { _name = name; }
void		ClapTrap::setHitPoints( const int &amount) { _hit_points = amount; }
void		ClapTrap::setEnergyPoints( const int &amount) { _energy_points = amount; }
void		ClapTrap::setAttackDmg( const int &amount) { _attack_dmg = amount; }

/* overload */
ClapTrap 	&ClapTrap::operator=(const ClapTrap &other)
{
	std::cout << "ClapTrap Assignation operator called" << std::endl;
	_name = other._name;
	_hit_points = other._hit_points;
	_energy_points = other._energy_points;
	_attack_dmg = other._attack_dmg;
	return *this;
}
	
/* ostream overload */
std::ostream	&operator<<(std::ostream &ostr, const ClapTrap &obj)
{
	ostr << "name: " << obj.getName() << ", hit points: " << obj.getHitPoints() 
		<< ", energy points: " << obj.getEnergyPoints() 
		<< ", attack damage: " << obj.getAttackDmg() << std::endl;
	return (ostr);
}

