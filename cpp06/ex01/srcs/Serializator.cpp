/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializator.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 18:23:54 by tjuvan            #+#    #+#             */
/*   Updated: 2025/01/10 13:11:45 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Serializator.hpp"

//constructor - private
Serializator::Serializator() {}
Serializator::Serializator( const Serializator &copy) { *this = copy; }
Serializator		&Serializator::operator=(const Serializator &other) {  if (this != &other) return (*this); return (*this); }
//deconstructor
Serializator::~Serializator() { std::cout << "scalar deconstructor\n"; }

//
uintptr_t		Serializator::serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data				*Serializator::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}


//overload
std::ostream		&operator<<(std::ostream &ostr, const Data &obj)
{
	ostr << obj.shit << "  " << obj.pee << "\n";
	for (int i = 0; i < 12; i++)
		ostr << obj.sleep[i] << ", ";
	ostr << "\n";

	return (ostr);
}
