/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 19:47:04 by tjuvan            #+#    #+#             */
/*   Updated: 2024/12/15 20:03:37 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <ctime>
#include <cstdlib>

class Brain
{
	public:
		/* getters/setters */
		std::string					getArrayMember( int	i ) const;
		std::string					getIdea( void ) const;
		int							getIndex() const;
		const std::string			*getArray( void ) const;
		static void					fillArray( void );
		void						incrementIndex( void );
		void						setIdea( std::string change );

		/* constructors */
		Brain( void );
		Brain( const Brain &copy);
		~Brain( void );

		/* overloads */
		Brain						&operator=( const Brain &other );
		
	protected:
		static std::string 			_ideas[100];
		static	int					_index;
		int							_personal_index;
		std::string					_idea;
};
std::ostream			&operator<<( std::ostream &ostr, const Brain &obj );
