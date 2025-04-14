/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 17:44:32 by tjuvan            #+#    #+#             */
/*   Updated: 2025/01/12 19:28:03 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <exception>
#include <cmath>
#include <limits.h>
#include <algorithm>
#include <sstream>


class	Span
{
	public:
		//constructors
					Span( void );
					Span( unsigned int N );
					Span( const Span &copy);
					~Span( void );
		//overloads
		Span		&operator=(const Span &other);

		//methods
		void		addNumber(const int &num);
		int			shortestSpan( void );
		int			longestSpan( void );
		void		printVect( void );
		int			size( void );


		//exceptions
		class		OutOfBound : public std::exception
		{
			public:
				OutOfBound(unsigned int size);
				virtual const char *what() const throw();
				virtual 			~OutOfBound() throw();
			private:
				unsigned int	_size;
				std::string 	_msg;
		};
		class		NoMembers : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

	private:
		unsigned int		_size;
		std::vector<int>	_vect;


};
