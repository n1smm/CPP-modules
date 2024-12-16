/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thiew <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 22:34:31 by thiew             #+#    #+#             */
/*   Updated: 2024/12/15 23:08:49 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Animal.hpp"

class	Dog : public Animal
{
	public:
		// method
		void	makeSound( void ) const;	
		void	print( std::ostream &ostr ) const; 

		// constructors
		Dog( void );
		Dog( const std::string type);
		Dog( const Dog &copy);
		~Dog( void );

		//overload
		Dog		&operator=(const Dog &other);

	private:
		Brain	*_brain;


};
