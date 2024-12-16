/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thiew <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 23:12:24 by thiew             #+#    #+#             */
/*   Updated: 2024/12/15 22:54:21 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"

// constructors
Cat::Cat() : Animal("Cat"), _brain(new Brain()) { _brain->setIdea("cat thinks: " + _brain->getIdea());  std::cout << "cat constructor\n"; }
Cat::Cat(const std::string type) : Animal(type), _brain(new Brain()) { _brain->setIdea("cat thinks: " + _brain->getIdea()); std::cout << "cat constructor\n"; }
Cat::Cat(const Cat &copy) : Animal(copy), _brain(new Brain(*copy._brain)) { std::cout << "cat constructor\n"; }
Cat::~Cat() { delete _brain; std::cout << "cat deconstructor\n"; }

// method
void	Cat::makeSound() const { std::cout << "Meow!\n"; }
void	Cat::print( std::ostream &ostr) const { ostr << "yass cat=> " << _brain->getIdea() << std::endl; }

//overload
Cat		&Cat::operator=(const Cat &other)
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
