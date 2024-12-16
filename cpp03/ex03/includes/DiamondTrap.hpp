/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 17:15:23 by tjuvan            #+#    #+#             */
/*   Updated: 2024/12/13 15:13:33 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap , public FragTrap 
{
	public:

		/* methods */
		void	whoAmI( void );

		/* constructors */
		DiamondTrap( void );
		DiamondTrap( const DiamondTrap &copy);
		DiamondTrap( const std::string name);
		~DiamondTrap();


	private:
		std::string _name;
};

