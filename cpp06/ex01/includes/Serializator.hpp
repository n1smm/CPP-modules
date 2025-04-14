/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 16:47:48 by tjuvan            #+#    #+#             */
/*   Updated: 2025/01/10 14:07:33 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <stdint.h>

typedef	struct	s_data
{
	int			shit;
	std::string	pee;
	double		sleep[12];
}				Data;

class	Serializator
{
	public:
	~Serializator( void );	

	static	uintptr_t	serialize( Data *ptr );
	static	Data		*deserialize( uintptr_t raw );

	private:
	Serializator( void );
	Serializator( const Serializator &copy);
	Serializator		&operator=(const Serializator &other);
	

};

std::ostream	&operator<<(std::ostream &ostr, const Data &obj);
