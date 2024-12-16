/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 18:24:12 by tjuvan            #+#    #+#             */
/*   Updated: 2024/12/04 11:42:13 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/HumanB.hpp"


HumanB::HumanB(std::string name) : _name(name), _weapon(NULL) {}
HumanB::~HumanB( void ) { std::cout << _name << " Has swung his last " << _weapon->getType() << std::endl; }


void	HumanB::setWeapon(Weapon &weapon) { _weapon = &weapon; }

void	HumanB::attack()
{
	if (_weapon) 
		std::cout << _name << " attacks with their " <<
			_weapon->getType() << std::endl;
	else
		std::cout << _name << " attacks with BARE HANDS\n";
}
