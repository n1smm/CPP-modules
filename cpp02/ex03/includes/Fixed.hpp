/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:37:08 by tjuvan            #+#    #+#             */
/*   Updated: 2024/12/08 13:23:45 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FIXED_HPP
#define	FIXED_HPP

#include <iostream>
#include <iomanip>

class Fixed
{
	public:

		/* methods */
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat( void ) const;
		int		toInt( void ) const;
		/* static methods */
		static	Fixed	&min(Fixed &a, Fixed &b);
		static	const Fixed	&min(const Fixed &a, const Fixed &b);
		static	Fixed	&max(Fixed &a, Fixed &b);
		static	const Fixed	&max(const Fixed &a, const Fixed &b);


		/* constructors */
		Fixed( void );
		Fixed(int const fixed);
		Fixed(float const fixed);
		Fixed( Fixed const	&other);

		/* overload operators */
		Fixed	&operator=(Fixed const &other);
		/* comparison operators */
		bool	operator<(Fixed const &other);
		bool	operator>(Fixed const &other);
		bool	operator<=(Fixed const &other);
		bool	operator>=(Fixed const &other);
		bool	operator==(Fixed const &other);
		bool	operator!=(Fixed const &other);
		/* arithmetic operators */
		/* float	operator+(ixed const &other); */
		/* float	operator-(Fixed const &other); */
		/* float	operator*(Fixed const &other); */
		/* float	operator/(Fixed const &other); */
		Fixed	operator+(Fixed const &other) const;
		Fixed	operator-(Fixed const &other) const;
		Fixed	operator*(Fixed const &other) const;
		Fixed	operator/(Fixed const &other) const;
		/* increment operators */
		Fixed	&operator++();
		Fixed	operator++(int);
		/* decrement operators */
		Fixed	&operator--();
		Fixed	operator--(int);


		/* deconstructor */
		~Fixed( void );

	private:

		int			_fixed;
		const int	_bits;

};

std::ostream	&operator<<(std::ostream &ostr, Fixed const &object);

#endif
