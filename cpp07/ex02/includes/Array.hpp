/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 16:47:35 by tjuvan            #+#    #+#             */
/*   Updated: 2025/01/11 23:53:59 by thiew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <exception>

template<typename T>
class	Array
{
	public:
		//constructors
							Array( void );
							Array( unsigned int n );
							Array( const Array &copy);
							~Array( void );
		//overloads
		Array				&operator=( const Array &other);
		T					&operator[]( unsigned int i );

		//methods
		unsigned	int		size( void );

		//exceptions
		class	OutOfBounds : public std::exception
		{
			virtual const	char	*what() const throw();
		};


	private:
		 T					*_array;
		 unsigned	int		_size;


};

#include "Array.tpp"
