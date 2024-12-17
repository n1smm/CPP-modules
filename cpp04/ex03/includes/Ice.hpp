/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 14:42:51 by tjuvan            #+#    #+#             */
/*   Updated: 2024/12/17 18:44:03 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AMateria.hpp"
#include "ICharacter.hpp"

class	Ice : public AMateria
{
	public:
		/* methods */
		Ice			*clone( void )	const;
		void				use(ICharacter &target);

		/* constructors */
		Ice( void );
		Ice( const std::string _type );
		Ice( const Ice &other );
		~Ice( void );

		/* overloads */
		Ice		&operator=( const Ice &other);


};
