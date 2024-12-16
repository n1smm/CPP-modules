/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:36:32 by tjuvan            #+#    #+#             */
/*   Updated: 2024/12/03 14:36:45 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

Zombie	*newZombie( std::string name)
{
	Zombie	*newZombie;
	newZombie = new	Zombie(name);
	return (newZombie);
}
