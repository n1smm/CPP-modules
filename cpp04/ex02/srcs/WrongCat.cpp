/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thiew <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 23:44:19 by thiew             #+#    #+#             */
/*   Updated: 2024/12/09 23:49:42 by thiew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/WrongCat.hpp"

// constructors
WrongCat::WrongCat() : WrongAnimal("WrongCat") { std::cout << "wrongcat constructor\n"; }
WrongCat::WrongCat(const std::string type) : WrongAnimal(type) { std::cout << "wrong cat constructor\n"; }
WrongCat::WrongCat(const WrongCat &copy) : WrongAnimal(copy) { std::cout << "wrong cat constructor\n"; }
WrongCat::~WrongCat() { std::cout << "wrong cat deconstructor\n"; }

// method
void	WrongCat::makeSound() const { std::cout << "GFLGSDFGEOFSDKFSD!\n"; }
