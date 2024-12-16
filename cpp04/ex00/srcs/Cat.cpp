/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thiew <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 23:12:24 by thiew             #+#    #+#             */
/*   Updated: 2024/12/09 23:33:49 by thiew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"

// constructors
Cat::Cat() : Animal("Cat") { std::cout << "cat constructor\n"; }
Cat::Cat(const std::string type) : Animal(type) { std::cout << "cat constructor\n"; }
Cat::Cat(const Cat &copy) : Animal(copy) { std::cout << "cat constructor\n"; }
Cat::~Cat() { std::cout << "cat deconstructor\n"; }

// method
void	Cat::makeSound() const { std::cout << "Meow!\n"; }
