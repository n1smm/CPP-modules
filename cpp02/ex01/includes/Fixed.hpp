/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:37:08 by tjuvan            #+#    #+#             */
/*   Updated: 2024/12/05 20:06:08 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FIXED_HPP
#define	FIXED_HPP

#include <iostream>

class Fixed
{
	public:

		/* methods */
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat( void ) const;
		int		toInt( void ) const;



		/* constructors */
		Fixed( void );
		Fixed(int const fixed);
		Fixed(float const fixed);
		Fixed( Fixed const	&other);
		/* overload operators */
		Fixed	&operator=(Fixed const &other);
		/* deconstructor */
		~Fixed( void );

	private:

		int			_fixed;
		const int	_bits;

};

std::ostream	&operator<<(std::ostream &ostr, Fixed const &object);

#endif
