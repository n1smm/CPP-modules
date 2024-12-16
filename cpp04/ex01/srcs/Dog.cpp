/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thiew <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 23:21:25 by thiew             #+#    #+#             */
/*   Updated: 2024/12/13 16:47:25 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/Dog.hpp"

// constructors
Dog::Dog() : Animal("Dog"), _brain(new Brain()) { _brain->setIdea("dog thinks: " + _brain->getIdea()); std::cout << "Dog constructor\n"; }
Dog::Dog(const std::string type) : Animal(type), _brain(new Brain()) { _brain->setIdea("dog thinks: " + _brain->getIdea()); std::cout << "Dog constructor\n"; }
Dog::Dog(const Dog &copy) : Animal(copy), _brain(new Brain(*copy._brain)) { std::cout << "Dog constructor\n"; }
Dog::~Dog() { delete _brain; std::cout << "Dog deconstructor\n"; }

// method
void	Dog::makeSound() const { std::cout << "Woof!\n"; }
void	Dog::print( std::ostream &ostr) const { ostr << "waa dog=> " << _brain->getIdea() << std::endl; }

//overload
Dog		&Dog::operator=(const Dog &other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		if (_brain)
			delete _brain;
		_brain = new Brain(*other._brain);
	}
	return (*this);
}
