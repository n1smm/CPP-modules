/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 12:08:38 by tjuvan            #+#    #+#             */
/*   Updated: 2024/12/19 16:45:55 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cure.hpp"

/* constructors */
Cure::Cure() : AMateria("cure") { std::cout << "cure def constr\n"; }
Cure::Cure(const Cure &other) : AMateria(other) { std::cout << "cure copy constr\n"; }
Cure::~Cure() { std::cout << "cure deconstr\n"; }
Cure::Cure(const std::string type) : AMateria(type) 
{ 
	if (type != "cure")
		throw std::invalid_argument("can only be Cure\n");
	std::cout << "cure type constr\n";
}

/* overload */
Cure	&Cure::operator=(const Cure &other)
{
	if (this != &other)
		_type = other._type;
	return (*this);
}

/* methods */
Cure		*Cure::clone() const { return (new Cure(*this)); }
void	Cure::use(ICharacter &target)
{
	std::cout << "* heals <" << target.getName() << "'s> wounds *\n"; 
}
