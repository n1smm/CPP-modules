/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:38:07 by tjuvan            #+#    #+#             */
/*   Updated: 2024/12/03 14:38:20 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "main.hpp"

void	randomChump( std::string name ) { Zombie newZombie(name); newZombie.announce(); }
