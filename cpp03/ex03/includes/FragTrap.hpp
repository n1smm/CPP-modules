/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 17:15:23 by tjuvan            #+#    #+#             */
/*   Updated: 2024/12/13 15:17:38 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	public:

		/* methods */
		void HighFivesGuys( void );

		/* constructors */
		FragTrap( void );
		FragTrap( const FragTrap &copy);
		FragTrap( const std::string name);
		~FragTrap();
};

