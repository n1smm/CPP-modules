/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 15:20:42 by tjuvan            #+#    #+#             */
/*   Updated: 2024/12/17 18:24:40 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma 	once
#include	"ICharacter.hpp"

class	Character: public ICharacter
{
	public:
		/* methods */
		std::string const	&getName( void )	const;
		void				equip( AMateria *m );
		void				unequip( int idx );
		void				use( int idx, ICharacter &target);

		/* constructors */
		Character( void );
		Character( std::string name );
		Character( const Character &other );
		~Character( void );

		/* overload */
		Character			&operator=( const Character &other);

	private:
		std::string			_name;
		int					_inventory[4];
};
