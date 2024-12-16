/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 19:24:41 by tjuvan            #+#    #+#             */
/*   Updated: 2024/12/13 12:11:59 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.hpp"

void	lbreak( void )
{
	std::cout << std::setw(50) << std::setfill('-') << "" << std::endl;
}

int	main(void)
{
	Weapon	club = Weapon("spiked club");
	Weapon	sword = Weapon("rusty sword");

	HumanA	bob("bob", club);
	HumanB	grub("grub");

	lbreak();
	bob.attack();
	club.setType("smelly finger");
	bob.attack();

	lbreak();
	grub.attack();
	grub.setWeapon(sword);
	grub.attack();
	sword.setType("magnificent ultra sword");
	grub.attack();
	lbreak();
	atexit(lbreak);
}
