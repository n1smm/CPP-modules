/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:50:09 by tjuvan            #+#    #+#             */
/*   Updated: 2024/12/13 11:54:05 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"
#include "Zombie.hpp"

Zombie	*zombieHorde( int N, std::string name)
{
	if (N <= 0) return (NULL);

	Zombie *zombies = new Zombie[N];	

	for(int	i = 0; i < N; i++)
		zombies[i] = Zombie(name); 
		/* zombies[i].set_name(name); */
	return (zombies);
}

void	hordeRoar(Zombie *zombies)
{
	std::cout << "--- The horde roars in unison ---\n";
	for (int i = 0; i < 10; i++)
		zombies[i].announce();
	std::cout << "--- The horde falls silent ---\n";
}

void	silentcry( void ) { std::cout << "--- *chirp* *chirp* ---\n"; }


