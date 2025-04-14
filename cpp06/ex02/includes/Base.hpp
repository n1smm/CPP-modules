/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 16:47:48 by tjuvan            #+#    #+#             */
/*   Updated: 2025/01/10 18:35:48 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <stdint.h>


class	Base
{
	public:
	virtual			~Base( void );	




};
	Base			*generate( void );
	void			identify( Base *p );
	void			identify( Base &p );

std::ostream		&operator<<(std::ostream &ostr, const Base &obj);
