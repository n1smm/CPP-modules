/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:24:56 by tjuvan            #+#    #+#             */
/*   Updated: 2024/12/04 11:48:54 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	MAIN_HPP
#define	MAIN_HPP

#include "Zombie.hpp"
#include <cstdlib>
 
Zombie	*zombieHorde( int N, std::string name);
void	hordeRoar(Zombie *zombies);
void	silentcry( void );

#endif
