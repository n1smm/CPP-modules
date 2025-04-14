/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fakemap.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thiew <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 11:34:16 by thiew             #+#    #+#             */
/*   Updated: 2025/02/11 11:07:30 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "Date.hpp"

typedef	Date	DateArray[4096];
typedef	double	DoubleArray[4096];

class FakeMap
{
	public:
		//methods
		void						insert(Date date, double value);
		//getters
		std::pair<Date, double>		getPair(Date const &date) const;
		Date						getDate( int it ) const;
		double						getValue( int it ) const;
		const	DateArray			&getDate( void ) const;
		const	DoubleArray			&getValue( void ) const;
		int							getSize( void ) const;

		//operator
		FakeMap						&operator=(const FakeMap &other);
		
		//constructor
		FakeMap( void );
		FakeMap( const FakeMap &copy);
		~FakeMap( void );


	private:
		double		_value[4096];
		Date		_date[4096];
		int			_size;

};

std::ostream	&operator<<(std::ostream &ostr, FakeMap const &other);
