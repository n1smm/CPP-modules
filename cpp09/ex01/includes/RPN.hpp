/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 19:17:21 by tjuvan            #+#    #+#             */
/*   Updated: 2025/02/11 21:11:43 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stack>
#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <exception>

class	RPN
{
	public:
		//constructors
		RPN( void );
		~RPN( void );
		RPN( const RPN &copy );
		RPN &operator=( const RPN &other );

		//methods
		static	void	calculate( char *input );


	private:
		static	std::stack<int>	_stack;





};
