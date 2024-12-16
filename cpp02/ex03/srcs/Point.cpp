/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 19:16:25 by tjuvan            #+#    #+#             */
/*   Updated: 2024/12/08 13:22:47 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Point.hpp"


/* defaults */
Point::Point() : _x(0), _y(0) {  }
Point::Point(const float x, const float y) :  _x(x), _y(y) {  }
Point::Point(const Point &other) : _x(other._x), _y(other._y) { }
Point::~Point() { }

Point	&Point::operator=(const Point &other)
{
	std::cout << "Point: reassignment on const not possible\n";
	if (this == &other)
		return (*this);
	return (*this);
}

/* methods */
const Fixed	&Point::get_x() const { return (_x); }
const Fixed	&Point::get_y() const { return (_y); }

/* os stream overload */

std::ostream &operator<<( std::ostream &ostr, const Point  &obj)
{
	ostr << std::setw(3) << "_x = " << obj.get_x() << std::setw(3) << "| _y = " << obj.get_y() << std::endl;
	return (ostr);
}



