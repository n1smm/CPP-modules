/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 14:17:28 by tjuvan            #+#    #+#             */
/*   Updated: 2024/12/19 12:10:13 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AMateria.hpp"
#include "ICharacter.hpp"

class	Cure : public AMateria
{
	public:
		/* methods */
		Cure			*clone( void )	const;
		void			use(ICharacter &target);

		/* constructors */
		Cure( void );
		Cure( const std::string _type );
		Cure( const Cure &other );
		~Cure( void );

		/* overloads */
		Cure		&operator=( const Cure &other);


};
