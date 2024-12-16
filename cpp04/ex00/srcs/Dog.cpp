/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thiew <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 23:21:25 by thiew             #+#    #+#             */
/*   Updated: 2024/12/09 23:33:39 by thiew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/Dog.hpp"

// constructors
Dog::Dog() : Animal("Dog") { std::cout << "cat constructor\n"; }
Dog::Dog(const std::string type) : Animal(type) { std::cout << "cat constructor\n"; }
Dog::Dog(const Dog &copy) : Animal(copy) { std::cout << "cat constructor\n"; }
Dog::~Dog() { std::cout << "cat deconstructor\n"; }

// method
void	Dog::makeSound() const { std::cout << "Woof!\n"; }
