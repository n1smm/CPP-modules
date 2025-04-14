/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Exchange.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thiew <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 21:23:01 by thiew             #+#    #+#             */
/*   Updated: 2025/02/11 18:15:45 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma 	once
#include	<iostream>
#include	<fstream>
#include 	<sstream>
#include 	<exception>
#include 	<algorithm>
#include	<string>
#include	<map>
#include 	"Date.hpp"
#include	"Fakemap.hpp"

class	Exchange
{
	public:
		//constructors
								Exchange( const FakeMap &input ); 
								Exchange( char *file_name);
								Exchange( const Exchange &copy );
								~Exchange( void );
				Exchange		&operator=( const Exchange &other );

		//methods
		static	bool					parseFile( std::ifstream &input, FakeMap	&ledger);
		static	bool					parseDB( std::ifstream &input, std::map<Date, double> &db);
		static	double					parseValue( std::string &input );
		static	void					checkFirstLine(std::ifstream &input,
										bool is_file, std::string whitespaces);

		//getters
		std::map<Date, double> 			&getMap( void );
		FakeMap							&getLedger( void );

		

	private:
		/* Date					_date; */
		double					_value;
		std::map<Date, double>	_DB;
		FakeMap					_ledger;

};

std::ostream	&operator<<(std::ostream &ostr, const Exchange &obj);
