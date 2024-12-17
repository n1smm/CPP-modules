/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 18:11:24 by tjuvan            #+#    #+#             */
/*   Updated: 2024/12/17 18:25:22 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Character.hpp"

/* constructors */
Character::Character() : _name("default"), _inventory() { std::cout << "char constr\n"; }
Character::Character(std::string name) : _name(name), _inventory() { std::cout << "char name constr\n"; }
Character::Character(const Character &other) : _name(other._name), _inventory() { std::cout << "char copy constr\n"; } //TODO
/* overload */
Character 	&Character::operator=(const Character &other)
{
	_name = other._name;
	return (*this);
}


/* methods */
std::string	const	&Character::getName() const { return (_name); }
