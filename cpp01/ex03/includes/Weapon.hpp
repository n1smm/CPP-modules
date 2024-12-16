/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 18:13:11 by tjuvan            #+#    #+#             */
/*   Updated: 2024/12/13 12:06:34 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	WEAPON_HPP
#define	WEAPON_HPP

#include <iostream>
 
class	Weapon
{
	public:
		const std::string	&getType( void ) const;
		void				setType( std::string type);

		Weapon();
		Weapon( std::string type );
		~Weapon( void );

	private:
		std::string	_type;
};

#endif
