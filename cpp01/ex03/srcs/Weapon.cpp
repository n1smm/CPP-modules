/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 17:57:51 by tjuvan            #+#    #+#             */
/*   Updated: 2024/12/13 12:07:23 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Weapon.hpp"

Weapon::Weapon( std::string type ) : _type(type) {}
Weapon::~Weapon( void ) { std::cout << "weapon " << _type << " destroyed\n"; }

const std::string	&Weapon::getType() const { return (_type); }
void				Weapon::setType( std::string type) { _type = type; }
