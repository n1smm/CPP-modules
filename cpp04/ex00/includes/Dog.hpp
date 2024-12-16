/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thiew <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 22:34:31 by thiew             #+#    #+#             */
/*   Updated: 2024/12/09 23:32:28 by thiew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Animal.hpp"

class	Dog : public Animal
{
	public:
		// mehtod
		void	makeSound( void ) const;	

		// constructors
		Dog( void );
		Dog( const std::string type);
		Dog( const Dog &copy);
		~Dog( void );


};
