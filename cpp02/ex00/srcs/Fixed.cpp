/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 16:35:54 by tjuvan            #+#    #+#             */
/*   Updated: 2024/12/05 17:17:31 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

/* special members */

Fixed::Fixed( void ) : _fixed(0), _bits(8) { std::cout << "default constructor\n"; }
Fixed::Fixed( int fixed ) : _fixed(fixed), _bits(8) { std::cout << "asignement constructor\n"; }

Fixed::~Fixed( void ) { std::cout << "deconstructor\n"; }

Fixed::Fixed( Fixed const &other) : _fixed(other._fixed), _bits(other._bits) { std::cout << "copy constructor \n"; }

Fixed	&Fixed::operator=(Fixed const &other) 
{ 
	std::cout << "asignement overload\n";
	if (this != &other)
		this->_fixed = other._fixed;

	return (*this);
}
/* ----------------------------------------------------- */
/* member functions */

int	Fixed::getRawBits() const { std::cout << _fixed << " getRawBits\n"; return (_fixed); }

void Fixed::setRawBits( int const raw ) { std::cout << "setRawBits\n"; _fixed = raw; }

