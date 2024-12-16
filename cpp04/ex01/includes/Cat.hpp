/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thiew <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 22:34:59 by thiew             #+#    #+#             */
/*   Updated: 2024/12/15 23:08:42 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"
#include <iostream>

class	Cat: public Animal
{
	public:
		// method
		void	makeSound( void ) const; 
		void	print( std::ostream &ostr ) const; 

		// constructors
		Cat( void );
		Cat( const std::string type);
		Cat( const Cat &copy);
		~Cat( void );

		// overload
		Cat	&operator=(const Cat &other);

	private:
		Brain	*_brain;


};
