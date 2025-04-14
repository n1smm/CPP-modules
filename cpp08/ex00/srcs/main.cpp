/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 16:37:38 by tjuvan            #+#    #+#             */
/*   Updated: 2025/02/06 13:06:56 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.hpp"

int	main(void)
{
	srand(time(0));

	//vector test
	std::vector<int> vect;
	vect.reserve(10);
	for (size_t i = 0; i < 10; i++)
	{
		if (i % 2)
			vect.insert(vect.begin(), i);
		else
			vect.push_back(i);
	}	
	for (size_t i = 0; i < vect.size(); i++)
		std::cout << vect.at(i) << "\t";
	std::cout << std::endl;
	try 
	{
		std::cout << "easy find test - vect \t";
		std::cout << *easyfind(vect, 4) << "\n";
		/* std::cout << *easyfind(vect, 11) << "\n"; */
	} catch (std::runtime_error &e)
	{ std::cout << e.what(); }


	//string test
	std::string str;
	str.reserve(10); 
	
	for (size_t i = 0; i < 10; i++) {
		char ch = 'a' + i; 
		if (i % 2) {
			str.insert(str.begin(), ch);
		} else {
			str.push_back(ch);
		}
	}
	for (size_t i = 0; i < str.size(); i++) {
		std::cout << str.at(i) << "\t";
	}
	std::cout << std::endl;

	try {
		std::cout << "easy find test - str \t";
		std::cout << *easyfind(str, 'd') << "\n";
		/* std::cout << *easyfind(str, 'z') << "\n"; */
	} catch (std::runtime_error &e) {
		std::cout << e.what() << std::endl;
	}

	//list tests
	std::list<float>	lst;
	for (size_t i = 0; i < 10; i++)
	{
		if (i % 2)
			lst.push_front(i);
		else
			lst.push_back(rand() / 10);
	}

	std::cout << "\nlist container test\n";
	for (std::list<float>::iterator it = lst.begin(); it != lst.end(); it++)
		std::cout << *it << "\n";

	try {
		std::cout << "\neasy find test -list \t";
		std::cout << *easyfind(lst, 3) << "\n";
		std::cout << *easyfind(lst, 4) << "\n";
		/* std::cout << *easyfind(str, 'z') << "\n"; */
	} catch (std::runtime_error &e) {
		std::cout << e.what() << std::endl;
	}
}
