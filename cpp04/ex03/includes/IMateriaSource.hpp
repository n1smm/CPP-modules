/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ImateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:16:21 by tjuvan            #+#    #+#             */
/*   Updated: 2024/12/17 16:19:31 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include "AMateria.hpp"

class	IMateriSource
{
	public:
		virtual	void		learnMateria( AMateria* ) 					= 0;
		virtual	AMateria	*createMateria( std::string const &type)	= 0;
		virtual				~IMateriSource( void ) {}
};
