/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Date.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thiew <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 21:35:13 by thiew             #+#    #+#             */
/*   Updated: 2025/02/11 11:26:39 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include <exception>
#include <ctime>

class	Date
{
	public:
		//consturctors
							Date( void );
							Date( std::string &unparsed );
							Date( const Date &copy );
							~Date( void );
				Date		&operator=( const Date &other );
				bool		operator<( const Date &other ) const;
				bool		operator>( const Date &other ) const;
				bool		operator==( const Date &other) const;

		// methods
				void		parseDate( std::string &unparsed );
		static	bool		isValidDate( const Date &uncheckedDate );
				std::string	formatDate() const;
		//getters
				int			getYear( void ) const;
				int			getMonth( void ) const;
				int			getDay( void ) const;



	private:
				int		_year;
				int		_month;
				int		_day;



};

std::ostream 	&operator<<(std::ostream &ostr, const Date &obj);
