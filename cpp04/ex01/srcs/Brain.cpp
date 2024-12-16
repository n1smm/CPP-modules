/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 20:32:13 by tjuvan            #+#    #+#             */
/*   Updated: 2024/12/15 22:38:58 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Brain.hpp"

/* random name generator */
std::string	random_name()
{
	std::string	output;

	for (int i = 0; i < 5; i++)
	{
		int c = 65 + (rand() % 26);
		output.push_back(c);

	}
	return (output);
}

/* static var init */ 
int	Brain::_index = 0;
std::string	Brain::_ideas[100];

/* constructors */
Brain::Brain() : _personal_index(_index), _idea(_ideas[_index]) 
{ 
	if (_index > 98)
		_index = 0;
	this->incrementIndex();
	std::cout << "Brain constructor\n";
}
Brain::Brain( const Brain &copy) : _personal_index(copy._index), _idea(copy._idea) 
{ 
	if (_index > 99)
		_index = 0;
	this->incrementIndex();
	std::cout << "Brain copy constr.\n";
}
Brain::~Brain() { std::cout << "Brain deconstruct\n"; }

/* getters/setters */
std::string			Brain::getArrayMember(int i) const { return (_ideas[i]); }
std::string			Brain::getIdea() const { return (_idea); }
const std::string	*Brain::getArray() const { return (_ideas); }
int					Brain::getIndex() const { return (_index); }
void				Brain::incrementIndex() { _index += 1; }
void				Brain::setIdea(std::string change) { _idea = change; } 
/* fill array */
void				Brain::fillArray()
{
	srand(time(0));
	static bool initialized = false;
	if (!initialized)
	{
		for(int i = 0; i <= 99; i++)
			_ideas[i] = random_name();
		initialized = true;
	}
}

/* overloads */
Brain			&Brain::operator=(const Brain &other) 
{
	if (this != &other)
	{
		this->_idea = other._idea;
		this->_personal_index = other._personal_index;
	}
	return (*this);
}
std::ostream	&operator<<(std::ostream &ostr, const Brain &obj) 
{ 
	ostr << "current index: " << obj.getIndex() << std::endl << "array" << obj.getArray() << std::endl;
	return (ostr);
}
