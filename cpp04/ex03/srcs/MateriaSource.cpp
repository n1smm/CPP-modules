/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 15:38:00 by tjuvan            #+#    #+#             */
/*   Updated: 2024/12/19 17:24:10 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/MateriaSource.hpp"

/* constructors */
MateriaSource::MateriaSource() : _source_inventory(), _inv_idx(0) { std::cout << "def MateriaSource const\n"; }

MateriaSource::MateriaSource(const MateriaSource &other) : _source_inventory() , _inv_idx(other._inv_idx)
{
	for (int i = 0; i <= other._inv_idx; i++)
		_source_inventory[i] = other._source_inventory[i]->clone();
	std::cout << "MateriaSource copy constr\n";
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i <= 3; i++)
		delete	_source_inventory[i];
	std::cout << "MateriaSource deconstr\n";
}

/* overload = */ 
MateriaSource		&MateriaSource::operator=(const MateriaSource &other)
{
	for (int i = 0; i <= _inv_idx; i++)
		delete	_source_inventory[i];

	_inv_idx = other._inv_idx;
	for (int i = 0; i <= other._inv_idx; i++)
		_source_inventory[i] = other._source_inventory[i]->clone();

	return (*this);
}

void	MateriaSource::learnMateria(AMateria *source)
{
	if (_inv_idx > 3 )
	{
		std::cout << "no free slot\n";
		return ;
	}
	_source_inventory[_inv_idx++] = source;
	std::cout << "MateriSource learned " << source->getType() << "\n";
}

AMateria	*MateriaSource::createMateria(std::string const &type)
{
	if (type != "ice" && type != "cure")
	{
		std::cout << "invalid type, can't create materia\n";
		return (0);
	}
	for (int i = 0; i <= _inv_idx; i++)
	{
		if (type == _source_inventory[i]->getType())
		{
			std::cout << "crated " << type << "\n";
			return (_source_inventory[i]->clone());
		}
	}
	std::cout << "No such Materia in MateriaSource, try addign it first!\n";
	return (0);
}
