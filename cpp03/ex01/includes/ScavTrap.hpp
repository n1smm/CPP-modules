/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 17:15:23 by tjuvan            #+#    #+#             */
/*   Updated: 2024/12/13 14:14:41 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
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
		/* ovlerload */
		ScavTrap &operator=(const ScavTrap &other);


	private:
		bool	_guarding;
};

