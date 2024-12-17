/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 15:00:21 by tjuvan            #+#    #+#             */
/*   Updated: 2024/12/17 15:20:08 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include "AMateria.hpp"

class	ICharacter
{
	public:
		/* methods */
		virtual	std::string const	&getName( void )	const			= 0;
		virtual	void				equip( AMateria *m ) 				= 0;
		virtual	void				unequip( int idx )					= 0;
		virtual	void				use( int idx, ICharacter &target)	= 0;
};
