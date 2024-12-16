/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 13:10:47 by tjuvan            #+#    #+#             */
/*   Updated: 2024/12/04 11:44:20 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	ZOMBIE_HPP
#define	ZOMBIE_HPP

#include <iostream>
#include <iomanip>

class	Zombie {

	public:
		void	announce( void );
		void	set_name( std::string name);

		Zombie();
		Zombie( std::string name );
		~Zombie( void );

	private:
		std::string	_name;

};

#endif
