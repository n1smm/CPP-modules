/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:38:41 by tjuvan            #+#    #+#             */
/*   Updated: 2024/12/19 16:10:37 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	public:
		/* methods */
		void				learnMateria( AMateria *source );
		AMateria			*createMateria( std::string const &type);

		/* constructors */
		MateriaSource( void );
		MateriaSource( const MateriaSource &other );
		~MateriaSource( void );

		/* overload */
		MateriaSource		&operator=( const MateriaSource &other);

	private:
		AMateria		*_source_inventory[4];
		int				_inv_idx;


};
