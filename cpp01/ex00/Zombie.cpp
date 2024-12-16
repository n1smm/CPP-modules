/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:01:13 by tjuvan            #+#    #+#             */
/*   Updated: 2024/12/03 14:40:51 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"Zombie.hpp"

Zombie::Zombie( std::string name ) { _name = name; }

Zombie::~Zombie( void ) { std::cout << "no braiiinzzz for " << _name << std::endl; }

void	Zombie::announce() { std::cout << _name << ": BraiiiiiiinnnzzzZ...\n"; }


