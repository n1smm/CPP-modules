/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 16:35:54 by tjuvan            #+#    #+#             */
/*   Updated: 2024/12/13 13:14:43 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"
#include <cmath>

/* special members */

/* constructors */
Fixed::Fixed( void ) : _fixed(0), _bits(8) { std::cout << "default constructor\n"; }

Fixed::Fixed( int const fixed ) : _fixed(fixed), _bits(8) 
{ 
	_fixed = fixed << _bits;
	std::cout << "int asignement constructor\n";
}
 
Fixed::Fixed( float const fixed) : _bits(8)
{
	_fixed = static_cast<int> (roundf(fixed * (1 << _bits)));
	std::cout << "float asignement constructor\n";
}

/* ----------------------------------------------------- */

/* deconstructor */
Fixed::~Fixed( void ) { std::cout << "deconstructor\n"; }

/* copy constructor */
Fixed::Fixed( Fixed const &other) : _fixed(other._fixed), _bits(other._bits) { std::cout << "copy constructor \n"; }

/* ----------------------------------------------------- */

/* overloads */
Fixed	&Fixed::operator=(Fixed const &other) 
{ 
	std::cout << "asignement overload\n";
	if (this != &other)
		this->_fixed = other._fixed;

	return (*this);
}

std::ostream	&operator<<(std::ostream &ostr, Fixed const &object)
{
	ostr << object.toFloat();
	return (ostr);
}

/* ----------------------------------------------------- */

/* comparison overloads */
bool	Fixed::operator<(Fixed const &other) { return (this->toFloat() < other.toFloat()); }
bool	Fixed::operator>(Fixed const &other) { return (this->toFloat() > other.toFloat()); }
bool	Fixed::operator>=(Fixed const &other) { return (this->toFloat() >= other.toFloat()); }
bool	Fixed::operator<=(Fixed const &other) { return (this->toFloat() <= other.toFloat()); }
bool	Fixed::operator==(Fixed const &other) { return (this->toFloat() == other.toFloat()); }
bool	Fixed::operator!=(Fixed const &other) { return (this->toFloat() != other.toFloat()); }

/* arithmetic overloads */
float	Fixed::operator+(Fixed const &other) { return (this->toFloat() + other.toFloat()); }
float	Fixed::operator-(Fixed const &other) { return (this->toFloat() - other.toFloat()); }
float	Fixed::operator*(Fixed const &other) { return (this->toFloat() * other.toFloat()); }
float	Fixed::operator/(Fixed const &other) { return (this->toFloat() / other.toFloat()); }

/* incr/decrement overloads */
Fixed	&Fixed::operator++() { this->_fixed++; return (*this); }
Fixed	&Fixed::operator--() { this->_fixed--; return (*this); }
Fixed	Fixed::operator++(int) { Fixed	tmp = *this; this->_fixed++; return (tmp); }
Fixed	Fixed::operator--(int) { Fixed	tmp = *this; this->_fixed--; return (tmp); }

/* ----------------------------------------------------- */

/* member functions */

int	Fixed::getRawBits() const { std::cout << _fixed << " getRawBits\n"; return (_fixed); }

void Fixed::setRawBits( int const raw ) { std::cout << "setRawBits\n"; _fixed = raw; }

int	Fixed::toInt() const {	return (_fixed >> _bits); }
float	Fixed::toFloat() const { return (static_cast<float> (_fixed) / static_cast<float> (1 << _bits)); }

/* ----------------------------------------------------- */
/* static methods */

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	float A = a.toFloat();
	float B = b.toFloat();

	if (A <= B)
		return (a);
	return (b);
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	float A = a.toFloat();
	float B = b.toFloat();

	if (A >= B)
		return (a);
	return (b);
}


const Fixed	&Fixed::min(const Fixed &a, const Fixed &b)
{
	float A = a.toFloat();
	float B = b.toFloat();

	if (A <= B)
		return (a);
	return (b);
}

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b)
{
	float A = a.toFloat();
	float B = b.toFloat();

	if (A >= B)
		return (a);
	return (b);
}
