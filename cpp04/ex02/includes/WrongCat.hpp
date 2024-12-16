/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thiew <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 22:36:07 by thiew             #+#    #+#             */
/*   Updated: 2024/12/09 23:43:49 by thiew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "WrongAnimal.hpp"

class	WrongCat: public WrongAnimal
{
	public:
		// mehtod
		void	makeSound( void ) const; 

		// constructors
		WrongCat( void );
		WrongCat( const std::string type);
		WrongCat( const WrongCat &copy);
		~WrongCat( void );


};
