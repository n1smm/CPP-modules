/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 12:12:40 by tjuvan            #+#    #+#             */
/*   Updated: 2024/12/08 13:21:10 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	POINT_HPP
#define POINT_HPP

#include <iostream>
#include <iomanip>
#include "Fixed.hpp"

class Point
{
	public:
		/* methods */
		const Fixed	&get_x( void ) const;
		const Fixed	&get_y( void) const;

		/* constructors */
		Point();
		Point(const float x, const float y);
		Point(const Point &other);
		~Point();

		Point	&operator=(const Point &other);

	
	private:
		Fixed const	_x;
		Fixed const	_y;

};

std::ostream &operator<<( std::ostream &ostr, Point const &obj);


#endif
