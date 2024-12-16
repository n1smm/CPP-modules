/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 17:15:23 by tjuvan            #+#    #+#             */
/*   Updated: 2024/12/13 14:56:56 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:

		/* methods */
		void HighFivesGuys( void );
		/* get/set */

		/* constructors */
		FragTrap( void );
		FragTrap( const FragTrap &copy);
		FragTrap( const std::string name);
		~FragTrap();


	private:
};

