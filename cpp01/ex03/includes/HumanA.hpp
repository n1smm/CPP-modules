/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 17:50:40 by tjuvan            #+#    #+#             */
/*   Updated: 2024/12/04 11:41:13 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	HUMAN_A_HPP
#define	HUMAN_A_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanA
{
	public:
		void	attack( void );

		HumanA(std::string name, Weapon &weapon);
		~HumanA( void );

	private:
		std::string	_name;
		Weapon	&_weapon;
};

#endif
