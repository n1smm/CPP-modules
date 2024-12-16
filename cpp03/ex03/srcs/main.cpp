/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 15:19:05 by tjuvan            #+#    #+#             */
/*   Updated: 2024/12/13 15:15:05 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.hpp"

int	main( void )
{
	DiamondTrap	Shiny("shiny");

	Shiny.whoAmI();

	std::cout << std::setw(30) << std::setfill('*') << "" << std::endl;
	std::cout << Shiny;
}
