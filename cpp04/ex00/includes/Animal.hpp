/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thiew <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 22:34:08 by thiew             #+#    #+#             */
/*   Updated: 2024/12/15 17:34:34 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Animal
{
	public:
		// methods
		virtual void	makeSound( void ) const;
		std::string		get_type( void ) const;

		// constructors
		Animal( void );
		Animal( const std::string type);
		Animal( const Animal &copy);
		virtual ~Animal( void );

        Animal &operator=(const Animal &other);


	protected:
		std::string		_type;
};

// ostream oveload
std::ostream	&operator<<( std::ostream &ostr, const Animal &obj);
