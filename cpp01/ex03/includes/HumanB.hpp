/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 19:09:27 by tjuvan            #+#    #+#             */ /*   Updated: 2024/12/03 19:16:18 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	HUMAN_B_HPP
#define	HUMAN_B_HPP

#include <iostream>
#include "Weapon.hpp"

class	HumanB
{
	public:
		void	attack( void );
		void	setWeapon(Weapon &weapon);

		HumanB(std::string name);
		~HumanB( void );

	private:
			std::string	_name;
			Weapon	*_weapon;

};

#endif
