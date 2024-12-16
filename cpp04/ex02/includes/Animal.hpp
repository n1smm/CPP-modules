/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thiew <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 22:34:08 by thiew             #+#    #+#             */
/*   Updated: 2024/12/15 22:58:06 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Brain.hpp"

class Animal
{
	public:
		/* methods */
		virtual void	makeSound( void ) const = 0;
		virtual	void	print( std::ostream &ostr ) const;
		std::string		get_type( void ) const;

		/* constructors */
		Animal( void );
		Animal( const std::string type);
		Animal( const Animal &copy);
		virtual ~Animal( void );

		/* = overload */
        Animal &operator=(const Animal &other);


	protected:
		std::string		_type;
};
/* ostream oveload */
std::ostream	&operator<<( std::ostream &ostr, const Animal &obj);
