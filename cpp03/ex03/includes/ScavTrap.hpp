/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 17:15:23 by tjuvan            #+#    #+#             */
/*   Updated: 2024/12/13 15:17:46 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	public:

		/* methods */
		void	GuardGate( void );
		/* get/set */
		void	setGate( const bool &value);
		bool	getGate( void ) const;

		/* constructors */
		ScavTrap( void );
		ScavTrap( const ScavTrap &copy);
		ScavTrap( const std::string name);
		~ScavTrap();

	protected:
		bool	_guarding;
};

