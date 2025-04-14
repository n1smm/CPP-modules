/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 17:44:06 by tjuvan            #+#    #+#             */
/*   Updated: 2025/01/12 19:36:53 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Span.hpp"

//constructors
			Span::Span() : _size(0), _vect() { std::cout << "def constructor\n"; }
			Span::Span(unsigned int N) : _size(N), _vect() { std::cout << "arg constructor\n"; }
			Span::Span(const Span &copy) : _size(copy._size), _vect()
			{
				if (copy._vect.empty() || copy._size < 1)
					return ;
				for (std::vector<int>::const_iterator it = copy._vect.begin(); it < copy._vect.end(); it++)
					this->_vect.push_back(*it);
			}
			Span::~Span() { std::cout << "decontructor\n"; }

//overload
Span		&Span::operator=(const Span &other)
{
	if (this != &other)
	{
		_size = other._size;
		_vect = other._vect;	
	}
	return (*this);
}
				
//methods
void		Span::addNumber(const int &num)
{
	if (_vect.size() >= _size)
		throw	OutOfBound(_size);
	_vect.push_back(num);
}

int			Span::shortestSpan()
{
	if (_vect.size() < 2)
		throw NoMembers();
	std::sort(_vect.begin(), _vect.end());
	int shortest = INT_MAX;
	int span = INT_MAX;
	for (std::vector<int>::iterator it = _vect.begin() + 1; it != _vect.end(); it++)
	{
		span = std::abs(*it - *(it -1));
		if (span < shortest)
			shortest = span;
	}
	return (shortest);
}

int			Span::longestSpan()
{
	if (_vect.size() < 2)
		throw NoMembers();
	std::sort(_vect.begin(), _vect.end());
	int longest = _vect.back() - _vect.front();
	return (longest);
}

void		Span::printVect()
{
	for (size_t i = 0; i < _vect.size(); i++)
		std::cout << _vect.at(i) << "\t";
	std::cout << std::endl;
}

int			Span::size()
{ return (_size); }

//exceptions
Span::OutOfBound::OutOfBound(unsigned int size) : _size(size)
{
	std::ostringstream oss;
	oss << "Error - out of bound > can only have "
		<< _size << " members\n";
	_msg = oss.str();
}
Span::OutOfBound::~OutOfBound() throw() {};
const char	*Span::OutOfBound::what() const throw()
{
	return (_msg.c_str());
}

const char	*Span::NoMembers::what() const throw()
{ return ("Error: No members or just 1 member in data structure\n"); }


