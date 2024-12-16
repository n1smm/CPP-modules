/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:37:08 by tjuvan            #+#    #+#             */
/*   Updated: 2024/12/05 15:56:54 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FIXED_HPP
#define	FIXED_HPP

#include <iostream>

class Fixed
{
	public:

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );



		Fixed( void );
		Fixed(int fixed);
		Fixed( Fixed const	&other);
		Fixed	&operator=(Fixed const &other);
		~Fixed( void );

	private:

		int			_fixed;
		const int	_bits;





};


#endif
