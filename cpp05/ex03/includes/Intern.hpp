/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 14:14:06 by tjuvan            #+#    #+#             */
/*   Updated: 2025/01/04 15:17:56 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AForm.hpp"

class	Intern
{
	public:

		//constructors
		Intern( void ) ;
		Intern( const Intern &copy);
		~Intern( void );
		// overload
		Intern		&operator=( const Intern &other);

		//method
		AForm		*makeForm( std::string formName, std::string targetName);
};
