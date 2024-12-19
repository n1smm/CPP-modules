/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 15:20:42 by tjuvan            #+#    #+#             */
/*   Updated: 2024/12/19 14:52:29 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma 	once
#include	"ICharacter.hpp"

class	Character: public ICharacter
{
	public:
		/* getters */
		std::string const	&getName( void )			const;
		std::string	const	&getMateriaInv( int idx)	const;
		std::string	const	&getMateriaDis( int idx)	const;
		int			const	&getInvIdx( void ) 			const;
		int			const	&getDisIdx( void )			const;
		/* methods */
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
		AMateria			*_inventory[4];
		AMateria			*_discarded[1024];
		int					_inv_index;
		int					_dis_index;
};

std::ostream				&operator<<( std::ostream &ostr, const Character &obj);
