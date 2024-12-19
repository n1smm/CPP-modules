/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 18:11:24 by tjuvan            #+#    #+#             */
/*   Updated: 2024/12/19 16:12:32 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Character.hpp"

/* constructors */
Character::Character() : _name("default"), _inventory(), _discarded(), _inv_index(0), _dis_index(0) { std::cout << "char constr\n"; }

Character::Character(std::string name) : _name(name), _inventory(), _discarded(), _inv_index(0), _dis_index(0) { std::cout << "char name constr\n"; }

Character::Character(const Character &other) : _name(other._name), _inventory(), _discarded(), _inv_index(other._inv_index), _dis_index(0) 
{ 
	for (int i = 0; i <= other._inv_index; i++)
		_inventory[i] = other._inventory[i]->clone();
	std::cout << "char copy constr\n";
}

/* overload = */
Character 			&Character::operator=(const Character &other)
{
	for (int i = 0; i <= _inv_index; i++)
		delete	_inventory[i];
	_name = other._name;
	_inv_index = other._inv_index;
	for (int i = 0; i <= other._inv_index; i++)
		_inventory[i] = other._inventory[i]->clone();
	return (*this);
}

/* deconstructor */
Character::~Character()
{
	for (int i = 0; i <= _inv_index; i++)
		delete	_inventory[i];
	for (int i = 0; i <= _dis_index; i++)
		delete	_discarded[i];
}

/* getters */
std::string	const	&Character::getName() 				const { return (_name); }
std::string	const	&Character::getMateriaInv(int idx)	const { return (_inventory[idx]->getType()); }
std::string	const	&Character::getMateriaDis(int idx)	const { return (_discarded[idx]->getType()); }
int			const	&Character::getInvIdx() 			const { return (_inv_index); }
int			const	&Character::getDisIdx() 			const { return (_dis_index); }

/* methods */
/* equip */
void				Character::equip(AMateria *m)
{
	if (_inv_index > 3)
	{
		std::cout << "Inventory full!\n";
		return ;
	}
	_inventory[_inv_index++] = m;
	std::cout << "equipped " << m->getType() << " to _inventory[" << _inv_index - 1 << "]\n";
}

/* unequip */
void				Character::unequip(int idx)
{
	if (idx > _inv_index && idx >= 0)
	{
		std::cout << "No Materia in this slot\n";
		return ;
	}
	_discarded[_dis_index++] = _inventory[idx];
	_inventory[idx] = NULL;
	for (int i = idx; i < _inv_index; i++)
		_inventory[i] = _inventory[i + 1];
	_inv_index--;
	std::cout << "unequipped " << _discarded[_dis_index - 1]->getType() << " from _inventory[" << idx << "]\n";
}

/* use */
void				Character::use(int idx, ICharacter &target)
{
	if (idx >= 0 && idx > _inv_index) 
	{
		std::cout << "No Materia in this slot\n";
		return ;
	}
	_inventory[idx]->use(target);
}

/* ostream overload */
void						print_inventory( std::ostream &ostr, const Character &obj)
{
	ostr << "inventory ->\t[";
	for (int i = 0; i <= obj.getInvIdx(); i++)
		ostr << obj.getMateriaInv(i) << "\t";
	ostr << "]\ndiscarderd ->\t[";
	for (int i = 0; i <= obj.getDisIdx(); i++)
		ostr << obj.getMateriaDis(i) << "\t";
	ostr << "]\n";
}

std::ostream				&operator<<( std::ostream &ostr, const Character &obj)
{
	std::cout << "*** " << obj.getName() << " ***\n";
	print_inventory(ostr, obj);
	return (ostr);
}
