/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 14:17:28 by tjuvan            #+#    #+#             */
/*   Updated: 2024/12/17 14:46:44 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AMateria.hpp"

class	Cure : public AMateria
{
	public:
		/* methods */
		Cure			*clone( void )	const;

		/* constructors */
		Cure( void );
		Cure( const std::string _type );
		Cure( const Cure &other );
		~Cure( void );

		/* overloads */
		Cure		&operator=( const Cure &other);


};
