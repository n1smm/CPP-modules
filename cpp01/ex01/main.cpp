/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:16:48 by tjuvan            #+#    #+#             */
/*   Updated: 2024/12/04 11:49:09 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

int	main( void )
{
	Zombie *zombies;
	int		Horde_size = 10;
	zombies = zombieHorde(Horde_size, "mimmo");
	hordeRoar(zombies);
	delete[] zombies;
	atexit(silentcry);
}
