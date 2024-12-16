/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 18:37:39 by tjuvan            #+#    #+#             */
/*   Updated: 2024/12/04 11:41:28 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/HumanA.hpp"


HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon) {}
HumanA::~HumanA( void ) { std::cout << "Human " << _name << " leaves the weapon on the battlefield\n"; }

void	HumanA::attack()
{
	std::cout << _name << " attacks with their " <<
		_weapon.getType() << std::endl;
}
