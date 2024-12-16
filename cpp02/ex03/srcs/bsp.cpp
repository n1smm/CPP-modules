/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 20:33:13 by tjuvan            #+#    #+#             */
/*   Updated: 2024/12/08 13:14:10 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Point.hpp"
#include "../includes/main.hpp"

 /* a, b, c: The vertices of our beloved triangle. */
/* • point: The point to check. */
/* • Returns: True if the point is inside the triangle. False otherwise. */
/* Thus, if the point is a vertex or on edge, it will return False. */

float	area_tri(Point const a, Point const b, Point const c)
{
	float area;
	float half = 0.5;

	area = half * ((a.get_x().toFloat() * (b.get_y().toFloat() - c.get_y().toFloat())) +
					(b.get_x().toFloat() * (c.get_y().toFloat() - a.get_y().toFloat())) +
					(c.get_x().toFloat() * (a.get_y().toFloat() - b.get_y().toFloat())));
	return (std::abs(area));
}

bool	bsp( Point const a, Point const b, Point const c, Point const point)
{
	float	A = area_tri(a, b, point);
	float	B = area_tri(a, c, point);
	float	C = area_tri(c, b, point);
	float	full = area_tri(a, b, c);
	float	tolerance = 0.01;
	bool	inside = true;
	
	if (A < tolerance || B < tolerance || C < tolerance)
		inside = false;
	if ( (A + B + C) - full > tolerance )
		inside =  false;
	return (inside);
}
