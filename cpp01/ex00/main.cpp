/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:16:48 by tjuvan            #+#    #+#             */
/*   Updated: 2024/12/03 14:46:14 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

int	main( void )
{
	Zombie zomb1("bono");
	randomChump( "mimo" );	
	Zombie *zomb2 = newZombie("bipo");
	zomb1.announce();
	zomb2->announce();
	delete zomb2;
}
