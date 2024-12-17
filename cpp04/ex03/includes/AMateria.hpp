/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:43:39 by tjuvan            #+#    #+#             */
/*   Updated: 2024/12/17 17:54:37 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class	ICharacter;

class	AMateria
{
	public:
		/* methods */
				std::string	const	&getType( void )		const;
		virtual AMateria			*clone( void ) 			const	= 0;
		virtual void				use(ICharacter &target)			= 0;

		/* constructors */
				AMateria( void );
				AMateria( const std::string _type );
				AMateria( const AMateria &other );
		virtual	~AMateria( void );

		/* overloads */
				AMateria			&operator=( const AMateria &other);


	protected:
				std::string			_type;
};

std::ostream	&operator<<( std::ostream &ostr, const AMateria &obj);
