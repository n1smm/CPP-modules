/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fakemap.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thiew <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 11:58:26 by thiew             #+#    #+#             */
/*   Updated: 2025/02/11 11:08:59 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fakemap.hpp"

//constructors
FakeMap::FakeMap() : _size(0) {};

FakeMap::FakeMap( const FakeMap &copy)
{
	_size = copy._size;
	if (_size <= 0)
		return ;
	for (int i = 0; i < _size; i++)
	{
		_value[i] = copy._value[i];
		_date[i] = copy._date[i];
	}
}

FakeMap		&FakeMap::operator=( const FakeMap &other)
{
	if (this != &other)
	{
		_size = other._size;
		for (int i = 0; i < _size; i++)
		{
			_value[i] = other._value[i];
			_date[i] = other._date[i];
		}
	}
	return (*this);
}

FakeMap::~FakeMap() {}


//methods -------------------------------

void		FakeMap::insert(Date date, double value)
{
	int		i = -1;

	if (_size >= 4096)
		throw std::runtime_error("can't insert anymore, reached maximum size for ledger map");

	while (++i < _size)
	{
		if (_date[i] > date)
			break ;
	}
	for (int it = _size - 1; it >= i; it--)
	{
		_date[it + 1] = _date[it];
		_value[it + 1] = _value[it];
	}
	_date[i] = date;
	_value[i] = value;
	_size++;
}

//getters -------------------

std::pair<Date, double>		FakeMap::getPair(Date const &date) const
{

	int i = 0;
	Date	false_date;
	while (i < _size)
	{
		if (_date[i] == date)
			break;
		i++;
	}
	if (i == _size)
		return (std::make_pair(false_date, -1));
	else
		return (std::make_pair(_date[i], _value[i]));
}

Date				FakeMap::getDate(int i) const
{ if (i < _size)	return (_date[i]); return(Date()); }
double				FakeMap::getValue(int i) const
{ if (i < _size)	return (_value[i]); return (-1); }
const	DateArray	&FakeMap::getDate() const
{ return (_date); }
const	DoubleArray	&FakeMap::getValue() const
{ return (_value); }
int					FakeMap::getSize() const
{ return (_size); }


// << overload ------------------
std::ostream 	&operator<<(std::ostream &ostr, const FakeMap &other)
{
	ostr << "  DATE \t\t\t\t | \t\t VALUE\n";
	ostr << " size: " << other.getSize() << std::endl;
	for (int i = 0; i < other.getSize(); i++)
	{
		ostr << "[ " << other.getDate(i) << " ]\t\t"
			<< "[ " << other.getValue(i) << " ]\n";
	}
	return (ostr);
}
