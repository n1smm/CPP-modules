/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thiew <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 22:35:53 by thiew             #+#    #+#             */
/*   Updated: 2024/12/16 11:16:15 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class WrongAnimal
{
	public:
		// methods
		void			makeSound( void ) const;
		std::string		get_type( void ) const;

		// constructors
		WrongAnimal( void );
		WrongAnimal( const std::string type);
		WrongAnimal( const WrongAnimal &copy);
		virtual ~WrongAnimal( void );

		// ostream oveload


	protected:
		std::string		_type;
};

std::ostream	&operator<<( std::ostream &ostr, const WrongAnimal &obj);
