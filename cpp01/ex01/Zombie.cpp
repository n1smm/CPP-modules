/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:01:13 by tjuvan            #+#    #+#             */
/*   Updated: 2024/12/04 11:44:11 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"Zombie.hpp"

Zombie::Zombie() {}
Zombie::Zombie( std::string name ) : _name(name) {};
Zombie::~Zombie( void ) { std::cout << "no braiiinzzz for " << _name << std::endl; }

void	Zombie::announce() { std::cout << _name << ": BraiiiiiiinnnzzzZ...\n"; }

void	Zombie::set_name( std::string name) { _name = name; }
