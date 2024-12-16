/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 13:50:25 by tjuvan            #+#    #+#             */
/*   Updated: 2024/12/13 14:06:48 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef	CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
	public:
		/* methods */
		void	attack( const std::string &target );
		void	takeDamage( unsigned int amount );
		void	beRepaired( unsigned int amount );

		/* geters */
		std::string getName( void ) const;
		int			getHitPoints( void ) const;
		int			getEnergyPoints( void ) const;
		int			getAttackDmg( void ) const;
		/* setters */
		void		setName( const std::string &name);
		void		setHitPoints( const int &amount);
		void		setEnergyPoints( const int &amount);
		void		setAttackDmg( const int &amount);


		/* constructors */
		ClapTrap( void );
		ClapTrap( const ClapTrap &copy);
		ClapTrap( const std::string name );
		virtual ~ClapTrap( void );
		/* ovlerload */
		ClapTrap &operator=(const ClapTrap &other);

	protected:
		std::string		_name;
		int				_hit_points;
		int				_energy_points;
		int				_attack_dmg;

};

std::ostream	&operator<<(std::ostream &os, const ClapTrap &obj);

#endif
