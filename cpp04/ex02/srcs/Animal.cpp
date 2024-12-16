/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thiew <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 22:44:43 by thiew             #+#    #+#             */
/*   Updated: 2024/12/15 20:02:50 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"

// constructors
Animal::Animal() : _type("Animal") { std::cout << " Animal constructor\n"; }
Animal::Animal( const std::string type ) : _type(type) { std::cout << " Animal constructor\n"; }
Animal::Animal( const Animal &copy) : _type(copy._type) { std::cout << "Animal constructor\n"; } 
Animal::~Animal() { std::cout << "Animal deconstructor\n"; }


// methods
void		Animal::makeSound() const { std::cout << "No sound\n"; }
std::string	Animal::get_type() const { return (_type); }
void		Animal::print(std::ostream &ostr) const { ostr << "animal type: " << _type << std::endl; }

// overload
Animal	&Animal::operator=(const Animal &other)
{
	if (this != &other)
		_type = other._type;
	return (*this);
}
	

// ostream overload 
std::ostream	&operator<<(std::ostream &ostr, const Animal &obj)
{
	obj.print(ostr);
	return (ostr);
}
