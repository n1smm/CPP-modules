/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thiew <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 23:24:08 by thiew             #+#    #+#             */
/*   Updated: 2024/12/16 11:14:09 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.hpp"

int	main(void)
{
	const	Animal *meta = new Animal();
	const	Animal *j = new Dog();
	const	Animal *i = new Cat();
	const	WrongAnimal *muta = new WrongAnimal();
	const	WrongAnimal *pip = new WrongCat();
	const	WrongCat	*cat = new WrongCat();
	WrongCat			newcat;
	Cat				f;
	Dog				m;


	i->makeSound();
	meta->makeSound();
	muta->makeSound();
	pip->makeSound();
	cat->makeSound();
	newcat.makeSound();
	j->makeSound();
	f.makeSound();
	m.makeSound();
	std::cout << "meta " << *meta << std::endl;
	std::cout << "muta " << *muta << std::endl;
	std::cout << "pip " << *pip << std::endl;
	std::cout << "i " << *i << std::endl;
	std::cout << "j " << *j << std::endl;
	std::cout << "f " << f << std::endl;
	std::cout << "m " << m << std::endl;
	std::cout << "cat " << cat << std::endl;
	std::cout << "newcat " << newcat << std::endl;
	
	
	delete	meta;
	delete	muta;
	delete	j;
	delete	i;
	delete 	pip;
	delete	cat;

}
