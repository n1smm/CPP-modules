/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:34:43 by tjuvan            #+#    #+#             */
/*   Updated: 2024/12/17 18:44:23 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Ice.hpp"

/* constructors */
Ice::Ice() : AMateria("ice") { std::cout << "Ice def constr\n"; }
Ice::Ice(const Ice &other) : AMateria(other) { std::cout << "Ice copy constr\n"; }
Ice::~Ice() { std::cout << "Ice deconstr\n"; }
Ice::Ice(const std::string type) : AMateria(type) 
{ 
	if (type != "ice")
		throw std::invalid_argument("can only be Ice\n");
	std::cout << "Ice type constr\n";
}

/* overload */
Ice	&Ice::operator=(const Ice &other)
{
	if (this != &other)
		_type = other._type;
	return (*this);
}

/* methods */
Ice		*Ice::clone() const { return (new Ice(*this)); }
void	Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at <" << target.getName() << "> \n"; 
}


