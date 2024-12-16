/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 21:49:16 by tjuvan            #+#    #+#             */
/*   Updated: 2024/12/04 22:41:38 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>

class	Harl
{
	public:
		void	complain(std::string level);

		Harl( void ) {}
		~Harl( void ) {}
	private:
		void	_debug( void );
		void	_info( void );
		void	_warning( void );
		void	_error( void );
};

#endif
