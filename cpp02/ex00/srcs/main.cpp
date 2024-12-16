/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 16:35:29 by tjuvan            #+#    #+#             */
/*   Updated: 2024/12/05 17:18:35 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.hpp"

int	main(void)
{
	Fixed	a;
	Fixed	b(10);
	Fixed	c(b);
	Fixed	d = c;

	a.getRawBits();
	a = b;
	a.getRawBits();
	b.getRawBits();
	c.getRawBits();
	d.getRawBits();
	a.setRawBits(20);
	a.getRawBits();
}
