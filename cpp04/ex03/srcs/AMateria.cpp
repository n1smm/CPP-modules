/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:06:20 by tjuvan            #+#    #+#             */
/*   Updated: 2024/12/17 17:35:23 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AMateria.hpp"

/* constructors */
AMateria::AMateria() : _type("no_type") { std::cout << "AMateria def constr\n"; }
AMateria::AMateria(const std::string type) : _type(type) { std::cout << "AMaterira type constr\n"; }
AMateria::AMateria(const AMateria &other) : _type(other._type) { std::cout << "AMateria copy constr\n"; }
AMateria::~AMateria() { std::cout << "AMateria deconstr\n"; }

/* overload */
AMateria	&AMateria::operator=(const AMateria &other)
{
	if (this != &other)
		_type = other._type;
	return (*this);
}

/* method */
std::string const	&AMateria::getType() const { return (_type); }

/* ostream overload */
std::ostream	&operator<<(std::ostream &ostr, const AMateria &obj)
{
	ostr << "type: " << obj.getType() << std::endl;
	return (ostr);
}

