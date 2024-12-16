/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thiew <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 23:41:32 by thiew             #+#    #+#             */
/*   Updated: 2024/12/16 11:12:07 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/WrongAnimal.hpp"

// constructors
WrongAnimal::WrongAnimal() : _type("WrongAnimal") { std::cout << "WrongAnimal constructor\n"; }
WrongAnimal::WrongAnimal( const std::string type ) : _type(type) { std::cout << "WrongAnimal constructor\n"; }
WrongAnimal::WrongAnimal( const WrongAnimal &copy) : _type(copy._type) { std::cout << "WrongAnimal constructor\n"; } 
WrongAnimal::~WrongAnimal() { std::cout << "WrongAnimal deconstructor\n"; }


// methods
void	WrongAnimal::makeSound() const { std::cout << "Very very wrong sound!\n"; }
std::string	WrongAnimal::get_type() const { return (_type); }


// ostream overload 
std::ostream	&operator<<(std::ostream &ostr, const WrongAnimal &obj)
{
	ostr << "wrong animal type: " << obj.get_type() << std::endl;
	return (ostr);
}
