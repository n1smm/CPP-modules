/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thiew <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 22:34:59 by thiew             #+#    #+#             */
/*   Updated: 2024/12/09 23:32:36 by thiew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"
#include <iostream>

class	Cat: public Animal
{
	public:
		// mehtod
		void	makeSound( void ) const; 

		// constructors
		Cat( void );
		Cat( const std::string type);
		Cat( const Cat &copy);
		~Cat( void );


};
